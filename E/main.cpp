//Aleksandra Prodziewicz
#include <iostream>
#include <string.h>

using namespace std;

class CAESAR_CLASS;

class PLAYER_CLASS {
    friend CAESAR_CLASS;
protected:
    void die() {
        currHealth = 0;
    }
public:
    string id;
    unsigned int maxHealth;
    unsigned int agility;
    unsigned int damage;
    unsigned int currHealth;
    unsigned int defense;
    PLAYER_CLASS *next;
    virtual void printParams() = 0;

    virtual unsigned int getRemainingHealth() {
        return ((currHealth * 100) / maxHealth);
    }

    virtual unsigned int getDamage() = 0;

    virtual unsigned int getAgility() = 0;

    virtual unsigned int getMaxHealth() {
        return maxHealth;
    }

    virtual unsigned int getCurrHealth() {
        return currHealth;
    }

    virtual unsigned int getDefence() {
        return defense;
    }

    virtual PLAYER_CLASS *getNext() {
        return next;
    }

    virtual string getId() {
        return id;
    }

    virtual void reallyDie() {
        die();
    }

    virtual void setNext(PLAYER_CLASS *tNext) {
        next = tNext;
    }

    virtual void setId(string newId) {
        id = newId;
    }

    virtual void takeDamage(unsigned int oppositesDamage) = 0;

    virtual void applyWinnerReward() = 0;

    virtual void cure() = 0;

    PLAYER_CLASS(unsigned int maxHP, unsigned int currHP, unsigned int att, unsigned int agg) {
        id = "";
        maxHealth = maxHP;
        currHealth = currHP;
        agility = agg;
        damage = att;
        defense = 0;
        next = NULL;
    }
    PLAYER_CLASS(unsigned int maxHP, unsigned int att, unsigned int agg) {
        id = "";
        maxHealth = maxHP;
        currHealth = maxHP;
        agility = agg;
        damage = att;
        defense = 0;
        next = NULL;
    }

    PLAYER_CLASS(string thisId, unsigned int maxHP, unsigned int currHP, unsigned int att, unsigned int agg) {
        id = thisId;
        maxHealth = maxHP;
        currHealth = currHP;
        agility = agg;
        damage = att;
        defense = 0;
        next = NULL;
    }

    PLAYER_CLASS() {
        id = "";
        maxHealth = 1;
        currHealth = 0;
        agility = 0;
        damage = 0;
        defense = 0;
        next = NULL;
    }
};

class CAESAR_CLASS {
    friend PLAYER_CLASS;
public:
    unsigned int attackCounter;
    unsigned int fighterCounter;
    void judgeDeathOfLife(PLAYER_CLASS *player) {
        if (player->getRemainingHealth() > 0) {
            if (fighterCounter != 0 && fighterCounter % 3 == 0) {
                if (attackCounter % 2 == 0) {
                    player->reallyDie();
                }
            }
        }
    }
};

class ARENA_CLASS {
private:
    CAESAR_CLASS cezar;
public:
    ARENA_CLASS(CAESAR_CLASS *cezarPointer) {
        cezar = *cezarPointer;
        cezar.attackCounter = 0;
        cezar.fighterCounter = 0;
    }

    void fight(PLAYER_CLASS *one, PLAYER_CLASS *two) {
        if (one->getRemainingHealth() > 0 && two->getRemainingHealth() > 0) {//if both are alive
            cezar.attackCounter = 0;
            PLAYER_CLASS *first;
            PLAYER_CLASS *second;
            if (one->getAgility() < two->getAgility()) {//determine first
                first = two;
                second = one;
            } else {
                first = one;
                second = two;
            }
            first->printParams();
            second->printParams();
            ///start fighting
            while (cezar.attackCounter < 40) {
                if (first->getRemainingHealth() > 0) {
                    second->takeDamage(first->getDamage());
                    cezar.attackCounter++;
                    second->printParams();
                    if (second->getRemainingHealth() < 10) {
                        break;
                    } else if (second->getRemainingHealth() > 0) {
                        first->takeDamage(second->getDamage());
                        cezar.attackCounter++;
                        first->printParams();
                        if (first->getRemainingHealth() == 0) {
                            first->reallyDie();
                            break;
                        } else if (first->getRemainingHealth() < 10) {
                            break;
                        }
                    } else if (second->getRemainingHealth() == 0) {
                        second->reallyDie();
                        break;
                    }
                }
            }
            if (first->getRemainingHealth() > 0) {
                cezar.fighterCounter++;
                cezar.judgeDeathOfLife(first);
                first->printParams();
                if(first->getRemainingHealth() > 0){
                    first->applyWinnerReward();
                    first->cure();
                }
            }
            if (second->getRemainingHealth() > 0) {
                cezar.fighterCounter++;
                cezar.judgeDeathOfLife(second);
                second->printParams();
                if(second->getRemainingHealth() > 0){
                    second->applyWinnerReward();
                    second->cure();
                }
            }
            first->printParams();
            second->printParams();
        }
    }
};

class HUMAN_CLASS : public virtual PLAYER_CLASS {
protected:
    string id;
public:
    HUMAN_CLASS(string thisId) : PLAYER_CLASS(thisId, 200, 200, 30, 10) {
        id = thisId;
        defense = 10;
    }

    HUMAN_CLASS(string thisId, unsigned int def) : PLAYER_CLASS(thisId, 200, 200, 30, 10) {
        id = thisId;
        defense = def;
    }

    /*HUMAN_CLASS(): PLAYER_CLASS(200, 200, 30, 10) {
        id = "";
        defense = 10;
    }*/
    void takeDamage(unsigned int thisDamage) {
        if (agility + defense < thisDamage) {
            if (currHealth <= thisDamage - agility - defense) {
                currHealth = 0;
            } else {
                currHealth = currHealth - (thisDamage - agility - defense);
            }
        }
    }

    void applyWinnerReward() {
        damage = damage + 2;
        agility = agility + 2;
    }

    unsigned int getDamage() {
        return damage;
    }

    void cure() {
        currHealth = maxHealth;
    }

    unsigned int getAgility() {
        return agility;
    }

    void printParams() {
        if (getRemainingHealth() > 0) {
            cout << id << ":" << maxHealth << ":" << currHealth << ":" << getRemainingHealth() << "%:" << damage << ":"
                 << agility << ":" << defense << endl;
        } else {
            cout << id << ":" << "R.I.P." << endl;
        }
    }
};

class BEAST_CLASS : public virtual PLAYER_CLASS {
protected:
    string id;
public:
    BEAST_CLASS(string thisId) : PLAYER_CLASS(thisId, 150, 150, 40, 20) {
        id = thisId;
    }

    /* BEAST_CLASS() : PLAYER_CLASS(150, 150, 40, 20) {
         id = "";
         maxHealth = 150;
         currHealth = 150;
         agility = 20;
         damage = 40;
         defense = 0;
     }*/
    void takeDamage(unsigned int thisDamage) {
        if (agility / 2 < thisDamage) {
            if (currHealth <= thisDamage - (agility / 2)) {
                currHealth = 0;
            } else {
                currHealth = currHealth - (thisDamage - (agility / 2));
            }
        }
    }

    void applyWinnerReward() {
        damage = damage + 2;
        agility = agility + 2;
    }

    void cure() {
        currHealth = maxHealth;
    }

    unsigned int getDamage() {
        if (getRemainingHealth() < 25) {
            return 2 * damage;
        } else {
            return damage;
        }
    }

    unsigned int getAgility() {
        return agility;
    }

    void printParams() {
        if (currHealth > 0) {
            cout << id << ":" << maxHealth << ":" << currHealth << ":" << getRemainingHealth() << "%:" << getDamage()
                 << ":"
                 << agility << endl;
        } else {
            cout << id << ":" << "R.I.P." << endl;
        }
    }
};

class BERSERKER_CLASS : public HUMAN_CLASS, public BEAST_CLASS {
    string humanId;
    string beastId;

    void printParams() {
        if (HUMAN_CLASS::getRemainingHealth() >= 25) {
            HUMAN_CLASS::printParams();
        } else if (HUMAN_CLASS::getRemainingHealth() < 25 && BEAST_CLASS::getRemainingHealth() > 0) {
            PLAYER_CLASS::setId(beastId);
            BEAST_CLASS::printParams();
        } else if (BEAST_CLASS::getRemainingHealth() == 0) {
            PLAYER_CLASS::setId(humanId);
            HUMAN_CLASS::printParams();
        }
    }

public:
    void applyWinnerReward() {
        damage = damage + 2;
        agility = agility + 2;
    }

    unsigned int getDamage() {
        if (getRemainingHealth() < 25) {
            return 2 * damage;
        } else {
            return damage;
        }
    }

    void cure() {
        currHealth = maxHealth;
    }

    unsigned int getAgility() {
        return agility;
    }

    string getThisId() {
        if (getRemainingHealth() >= 25 || getRemainingHealth() == 0) {
            return humanId;
        } else {
            return beastId;
        }
    }

    BERSERKER_CLASS(string humanId, string beastId) : HUMAN_CLASS(humanId, 15),
                                                      BEAST_CLASS(beastId), PLAYER_CLASS(humanId, 200, 200, 35, 5) {
        this->humanId = humanId;
        this->beastId = beastId;
    };

    void takeDamage(unsigned int sth) {
        if (HUMAN_CLASS::getRemainingHealth() >= 25) {
            HUMAN_CLASS::takeDamage(sth);
        } else if (HUMAN_CLASS::getRemainingHealth() < 25 && BEAST_CLASS::getRemainingHealth() > 0) {
            /* if(BEAST_CLASS:: currHealth == 0){//idk
             }*/
            PLAYER_CLASS::setId(beastId);
            BEAST_CLASS::takeDamage(sth);
        } else if (BEAST_CLASS::getRemainingHealth() == 0) {
            PLAYER_CLASS::setId(humanId);
            HUMAN_CLASS::reallyDie();
        }
    }
};

class SQUAD_CLASS : public virtual PLAYER_CLASS {
public:
    friend PLAYER_CLASS;
    string squadId;
    PLAYER_CLASS *first;

    void addPlayer(PLAYER_CLASS *thisPlayer) {
        if (thisPlayer->getRemainingHealth() > 0) {
            if (first == NULL) {
                first = thisPlayer;
                maxHealth = thisPlayer->getMaxHealth();
            } else {
                PLAYER_CLASS *currPlayer = first;
                if (thisPlayer != first) {
                    while (currPlayer->getNext() != NULL) {
                        currPlayer = currPlayer->getNext();
                        if (currPlayer == thisPlayer) {
                            break;
                        }
                    }
                    if (currPlayer != thisPlayer) {
                        currPlayer->setNext(thisPlayer);
                        maxHealth = maxHealth + thisPlayer->getMaxHealth();
                    }
                }
            }
        }
    }

    SQUAD_CLASS(string id) : PLAYER_CLASS(0, 0, 0, 0) {
        squadId = id;
        first = NULL;
    }

    void swap(PLAYER_CLASS **headR, PLAYER_CLASS *currOne, PLAYER_CLASS *currTwo, PLAYER_CLASS *prevTwo) {
        if(prevTwo == NULL){
            *headR = currOne;
            PLAYER_CLASS *temp = currTwo->getNext();
            currTwo->setNext(currOne->getNext());
            currOne->setNext(temp);
        }else {
            *headR = currTwo;
            prevTwo->setNext(currOne);
            PLAYER_CLASS *temp = currTwo->getNext();
            currTwo->setNext(currOne->getNext());
            currOne->setNext(temp);
        }
    }

    PLAYER_CLASS *sort(PLAYER_CLASS *currStart) {
        if (currStart->getNext() == NULL) {
            return currStart;
        }
        PLAYER_CLASS *smallest = currStart;
        PLAYER_CLASS *prevSmallest = NULL;
        for (PLAYER_CLASS *currPlayer = currStart; currPlayer->getNext() != NULL; currPlayer = currPlayer->getNext()) {
            if (isTwoSmaller(smallest, currPlayer->getNext())) {
                smallest = currPlayer->getNext();
                prevSmallest = currPlayer;
            }
        }
        swap(&currStart, currStart, smallest, prevSmallest);
        PLAYER_CLASS *newStart = currStart->getNext();
        currStart->setNext(sort(newStart));// recursively sort the remaining list
        return currStart;
    }

    bool isTwoSmaller(PLAYER_CLASS *one, PLAYER_CLASS *two) {
        if (one->getId() != two->getId()) {
            if (one->getId() > two->getId()) {
                return true;
            }
        } else {
            if (one->getMaxHealth() > two->getMaxHealth()) {
                return true;
            } else if (one->getMaxHealth() == two->getMaxHealth()) {
                if (one->getCurrHealth() > two->getCurrHealth()) {
                    return true;
                } else if (one->getCurrHealth() == two->getCurrHealth()) {
                    if (one->getRemainingHealth() > two->getRemainingHealth()) {
                        return true;
                    } else if (one->getRemainingHealth() == two->getRemainingHealth()) {
                        if (one->getDamage() > two->getDamage()) {
                            return true;
                        } else if (one->getDamage() == two->getDamage()) {
                            if (one->getAgility() > two->getAgility()) {
                                return true;
                            } else if (one->getAgility() == two->getAgility()) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    void deleteFromSquad(PLAYER_CLASS *thisOne) {
        if (thisOne == first) {
            PLAYER_CLASS *newFirst = first->getNext();
            first = newFirst;
        } else {
            PLAYER_CLASS *currPlayer = first;
            if (first != NULL) {
                while (currPlayer->getNext() != thisOne) {
                    currPlayer = currPlayer->getNext();
                }
                PLAYER_CLASS *newNext = thisOne->getNext();
                currPlayer->setNext(newNext);
            }
        }
    }

    unsigned int getAgility() {
        actualise();
        PLAYER_CLASS *currPlayer = first;
        unsigned int currAgility = 0;
        if (first != NULL) {
            currAgility = first->getAgility();
            while (currPlayer->getNext() != NULL) {
                currPlayer = currPlayer->getNext();
                if (currPlayer->getAgility() < currAgility) {
                    currAgility = currPlayer->getAgility();
                }
            }
        }
        return currAgility;
    }

    void actualise() {
        PLAYER_CLASS *currPlayer = first;
        while (currPlayer != NULL) {
            if (currPlayer->getRemainingHealth() == 0) {
                deleteFromSquad(currPlayer);
            }
            currPlayer = currPlayer->getNext();
        }
    }

    unsigned int getDamage() {
        actualise();
        unsigned int currDamage = 0;
        if (first != NULL) {
            PLAYER_CLASS *currPlayer = first;
            currDamage = first->getDamage();
            while (currPlayer->getNext() != NULL) {
                currPlayer = currPlayer->getNext();
                currDamage = currDamage + currPlayer->getDamage();
            }
        }
        return currDamage;
    }

    void applyWinnerReward() {
        PLAYER_CLASS *currPlayer = first;
        while (currPlayer != NULL) {
            currPlayer->applyWinnerReward();
            currPlayer = currPlayer->getNext();
        }
    }

    void cure() {
        PLAYER_CLASS *currPlayer = first;
        while (currPlayer != NULL) {
            currPlayer->cure();
            currPlayer = currPlayer->getNext();
        }
    }

    unsigned int getRemainingHealth() {
        actualise();
        unsigned int currHP = 0;
        if (first != NULL) {
            PLAYER_CLASS *currPlayer = first;
            currHP = first->getRemainingHealth();
            while (currPlayer->getNext() != NULL) {
                currPlayer = currPlayer->getNext();
                if (currPlayer->getRemainingHealth() > currHP) {
                    currHP = currPlayer->getRemainingHealth();
                }
            }
        }
        return currHP;
    }

    unsigned int getCurrHealth() {
        actualise();
        unsigned int currHP = 0;
        if (first != NULL) {
            PLAYER_CLASS *currPlayer = first;
            currHP = first->getCurrHealth();
            while (currPlayer->getNext() != NULL) {
                currPlayer = currPlayer->getNext();
                currHP = currHP + currPlayer->getCurrHealth();
            }
        }
        return currHP;
    }

    unsigned int getPlayersAmount() {
        actualise();
        PLAYER_CLASS *currPlayer = first;
        unsigned int playerAmount = 0;
        while (currPlayer != NULL) {
            currPlayer = currPlayer->getNext();
            playerAmount++;
        }
        return playerAmount;
    }

    void takeDamage(unsigned int overallDamage) {
        actualise();
        if (first != NULL) {
            PLAYER_CLASS *currPlayer = first;
            unsigned int realDamage = overallDamage / getPlayersAmount();
            while (currPlayer != NULL) {
                currPlayer->takeDamage(realDamage);
                currPlayer = currPlayer->getNext();
            }
        }
    }

    void reallyDie() {
        PLAYER_CLASS *currPlayer = first;
        while (currPlayer != NULL) {
            currPlayer->reallyDie();
            currPlayer = currPlayer->getNext();
        }
    }

    void printParams() {
        actualise();
        if (first != NULL) {
            cout << squadId << ":" << getPlayersAmount() << ":" << getRemainingHealth() << "%:" << getDamage() << ":"
                 << getAgility() << endl;
            if (first != NULL) {
                first = sort(first);
                PLAYER_CLASS *currPlayer = first;
                currPlayer->printParams();
                while (currPlayer->getNext() != NULL) {
                    currPlayer = currPlayer->getNext();
                    currPlayer->printParams();
                }
            }
        } else {
            cout << squadId << ":nemo" << endl;
        }
    }
};
