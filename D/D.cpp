//Aleksandra Prodziewicz
#include <iostream>
class GARDEN_CLASS;
class WOOD_CLASS;
class BRANCH_CLASS;
class FRUIT_CLASS;

class FRUIT_CLASS
private:

    FRUIT_CLASS *next;
    FRUIT_CLASS *prev;
    unsigned int weight;
    unsigned int length;
    BRANCH_CLASS *isOn;
public:
    FRUIT_CLASS() {
        next = NULL;
        prev = NULL;
        weight = 0;
        length = 0;
        isOn = NULL;
    }
    FRUIT_CLASS(const FRUIT_CLASS& other);
    FRUIT_CLASS(unsigned int length, BRANCH_CLASS *isOn);
    ~FRUIT_CLASS();
    unsigned int getLength() const {
        return length;
    }
    unsigned int getWeight() const {
        return weight;
    }
    FRUIT_CLASS *getNext() {
        return next;
    }
    FRUIT_CLASS *getPrev() {
        return prev;
    }
    void setNext(FRUIT_CLASS* n) {
        this->next = n;
    }
    void setPrev(FRUIT_CLASS *p) {
        this->prev = p;
    }
    void setLength(unsigned int len) {
        this->length = len;
    }
    void setWeight(unsigned int wei) {
        this->weight = wei;
    }
    void setBranch(BRANCH_CLASS* bran) {
        this->isOn = bran;
    }
    BRANCH_CLASS* getBranchPointer() const{
        return isOn;
    }
    void growthFruit();
    void fadeFruit();
    void pluckFruit();
};
class BRANCH_CLASS {
private:
    BRANCH_CLASS *next;
    BRANCH_CLASS *prev;
    unsigned int length;
    unsigned int height;
    unsigned int fruitTotalAmount;
    unsigned int fruitTotalWeight;
    FRUIT_CLASS *firstFruit;
    WOOD_CLASS *isOn;
public:
    BRANCH_CLASS() {
        next = NULL;
        prev = NULL;
        length = 0;
        height = 0;
        fruitTotalAmount = 0;
        fruitTotalWeight = 0;
        firstFruit = NULL;
        isOn = NULL;
    }
    BRANCH_CLASS(const BRANCH_CLASS &other);
    BRANCH_CLASS(WOOD_CLASS *isOn, unsigned int height);
    ~BRANCH_CLASS();

    BRANCH_CLASS *getNext() {
        return next;
    }

    BRANCH_CLASS *getPrev() {
        return prev;
    }

    void setNext(BRANCH_CLASS *n) {
        this->next = n;
    }

    void setPrev(BRANCH_CLASS *p) {
        this->prev = p;
    }

    unsigned int getFruitsTotal() const {
        return fruitTotalAmount;
    }

    unsigned int getWeightsTotal() const  {
        return fruitTotalWeight;
    }
    void setFruitsTotal(unsigned int fruitsTotal) {
        this->fruitTotalAmount = fruitsTotal;
    }

    void setWeightsTotal(unsigned int weightsTotal){
        this-> fruitTotalWeight = weightsTotal;
    }

    unsigned int getHeight() const  {
        return height;
    }

    unsigned int getLength() const  {
        return length;
    }

    FRUIT_CLASS *getFirst() const{
        return firstFruit;
    }

    void setFirst(FRUIT_CLASS *ff) {
        this->firstFruit = ff;
    }

    WOOD_CLASS *getWoodPointer() const{
        return isOn;
    }
    void setWoodPointer(WOOD_CLASS *wood){
        this->isOn = wood;
    }
    void setLength(unsigned int newLength) {
        this->length = newLength;
    }
    void setHeight(unsigned int newHeight) {
        this->height = newHeight;
    }

    void growthBranch();
    void fadeBranch();
    void harvestBranch(unsigned int minimalWeight);
    void cutBranch(unsigned int newLength);
    FRUIT_CLASS *getFruitPointer(unsigned int fruitOnLength);

    void displayAll();
};
class WOOD_CLASS {
private:
    WOOD_CLASS *next;
    WOOD_CLASS *prev;
    unsigned int woodId;
    unsigned int height;
    unsigned int branchesAmount;
    unsigned int fruitsAmount;
    unsigned int weightsAmount;
    BRANCH_CLASS *firstBranch;
    GARDEN_CLASS *isIn;
public:
    WOOD_CLASS() {
        next = NULL;
        prev = NULL;
        woodId = 0;
        height = 0;
        branchesAmount = 0;
        fruitsAmount = 0;
        weightsAmount = 0;
        firstBranch = NULL;
        isIn = NULL;
    }
    WOOD_CLASS(const WOOD_CLASS &other);
    explicit WOOD_CLASS(unsigned int woodId, GARDEN_CLASS *isIn = NULL, bool isLast = true);
    ~WOOD_CLASS();
    void setFruitsTotal(unsigned int fruitsTotal) {
        fruitsAmount = fruitsTotal;
    }

    void setWeightsTotal(unsigned int weightsTotal){
        weightsAmount = weightsTotal;
    }

    unsigned int getBranchesTotal() const  {
        return branchesAmount;
    }

    unsigned int getFruitsTotal() const  {
        return fruitsAmount;
    }

    unsigned int getWeightsTotal() const  {
        return weightsAmount;
    }

    unsigned int getNumber() const  {
        return woodId;
    }

    unsigned int getHeight() const  {
        return height;
    }

    WOOD_CLASS *getNext() {
        return next;
    }

    WOOD_CLASS *getPrev() {
        return prev;
    }

    BRANCH_CLASS *getFirst() const{
        return firstBranch;
    }

    void setFirst(BRANCH_CLASS *firstBranch) {
        this->firstBranch = firstBranch;
    }
    void setNumber(unsigned int id){
        this->woodId = id;
    }

    void setNext(WOOD_CLASS *next) {
        this->next = next;
    }

    void setPrev(WOOD_CLASS *prev) {
        this->prev = prev;
    }
    void setGarden(GARDEN_CLASS *garden){
        this->isIn = garden;
    }
    void growthWood();
    void fadeWood();
    void harvestWood(unsigned int minimalWeight);
    void cutWood(unsigned int newHeight);
    void cloneBranch(BRANCH_CLASS *toClone);
    void setBranchesTotal(unsigned int i);

    BRANCH_CLASS *getBranchPointer(unsigned int heightOfBranch);
    GARDEN_CLASS *getGardenPointer() const{
        return isIn;
    }

    void displayAll();
};
class GARDEN_CLASS {
private:
    unsigned int woodTotalAmount;
    unsigned int branchesTotalAmount;
    unsigned int fruitsTotalAmount;
    unsigned int weightsTotalAmount;
    WOOD_CLASS *firstWood;
public:
    GARDEN_CLASS() {
        woodTotalAmount = 0;
        branchesTotalAmount = 0;
        weightsTotalAmount = 0;
        fruitsTotalAmount = 0;
        firstWood = NULL;
    }
    ~GARDEN_CLASS() {
        if(woodTotalAmount > 0){
            WOOD_CLASS *currWood = firstWood->getPrev();
            while (firstWood != currWood) {
                currWood = currWood->getPrev();
                delete currWood->getNext();
            }
            delete currWood;
        }
        woodTotalAmount = 0;
        branchesTotalAmount = 0;
        weightsTotalAmount = 0;
        fruitsTotalAmount = 0;
        firstWood = NULL;
    }

    unsigned int getWoodsTotal()  const{
        return woodTotalAmount;
    }

    unsigned int getBranchesTotal()  const{
        return branchesTotalAmount;
    }

    unsigned int getFruitsTotal()  const{
        return fruitsTotalAmount;
    }
    void setFruitsTotal(unsigned int fruits){
        this->fruitsTotalAmount = fruits;
    }
    unsigned int getWeightsTotal()  const{
        return weightsTotalAmount;
    }
    void setBranchesTotal(unsigned int i){
        this->branchesTotalAmount = i;
    }
    void setWoodsTotal(unsigned int i){
        this->woodTotalAmount = i;
    }

    WOOD_CLASS *getFirst() const{
        return firstWood;
    }

    void setFirst(WOOD_CLASS* firstWood) {
        this->firstWood = firstWood;
    }

    void plantWood();

    void extractWood(unsigned int toExtractId);

    void growthGarden();

    void fadeGarden();

    void harvestGarden(unsigned int minimalWeight);

    void cloneWood(unsigned int toCloneId);

    WOOD_CLASS *getWoodPointer(unsigned int woodId);

    void setWeightsTotal(unsigned int i);

    void displayAll();
};

FRUIT_CLASS::FRUIT_CLASS( unsigned int length, BRANCH_CLASS *isOn) {
    this->weight = 0;
    this->length = length;
    this->isOn = isOn;
    if(isOn != NULL) {
        if (isOn->getFruitsTotal() == 0) {
            isOn->setFirst(this);
            this->next = this;
            this->prev = this;
        } else {
            FRUIT_CLASS *prePrev = isOn->getFirst()->getPrev();
            prePrev->setNext(this);
            this->prev = prePrev;
            isOn->getFirst()->setPrev(this);
            this->next = isOn->getFirst();
        }
        isOn->setFruitsTotal(isOn->getFruitsTotal() + 1);
        if (isOn->getWoodPointer() != NULL) {
            isOn->getWoodPointer()->setFruitsTotal(isOn->getWoodPointer()->getFruitsTotal() + 1);
            if (isOn->getWoodPointer()->getGardenPointer() != NULL) {
                isOn->getWoodPointer()->getGardenPointer()->setFruitsTotal(
                        isOn->getWoodPointer()->getGardenPointer()->getFruitsTotal() + 1);
            }
        }
    }
    else{
        this -> next = this;
        this -> prev = this;
    }
}
FRUIT_CLASS::~FRUIT_CLASS() {
    if(isOn != NULL ) {
        if (isOn->getFruitsTotal() > 0) {
            isOn->setFruitsTotal(isOn->getFruitsTotal() - 1);
        }
        if (isOn->getWeightsTotal() - weight >= 0) {
            isOn->setWeightsTotal((isOn->getWeightsTotal()) - weight);
        }
        if (isOn->getWoodPointer() != NULL) {
            isOn->getWoodPointer()->setFruitsTotal(isOn->getWoodPointer()->getFruitsTotal() - 1);
            isOn->getWoodPointer()->setWeightsTotal(isOn->getWoodPointer()->getWeightsTotal() - weight);
            if (isOn->getWoodPointer()->getGardenPointer() != NULL) {
                isOn->getWoodPointer()->getGardenPointer()->setFruitsTotal(
                        isOn->getWoodPointer()->getGardenPointer()->getFruitsTotal() - 1);
                isOn->getWoodPointer()->getGardenPointer()->setWeightsTotal(
                        isOn->getWoodPointer()->getGardenPointer()->getWeightsTotal() - weight);
            }
        }
        if(this == isOn->getFirst() && isOn->getFirst() == isOn->getFirst()->getPrev()){
            next = NULL;
            prev = NULL;
            isOn->setFirst(NULL);
        }
        else{
            FRUIT_CLASS*newNext = this->getNext();
            FRUIT_CLASS *newPrev = this->getPrev();
            next->setPrev(newPrev);
            prev->setNext(newNext);
        }
    }
    weight = 0;
    length = 0;
}
void FRUIT_CLASS::growthFruit() {
    weight++;
    if(isOn != NULL){
        isOn->setWeightsTotal((isOn->getWeightsTotal()) + 1);
        if (isOn->getWoodPointer() != NULL) {
            isOn->getWoodPointer()->setWeightsTotal(isOn->getWoodPointer()->getWeightsTotal() + 1);
            if (isOn->getWoodPointer()->getGardenPointer() != NULL) {
                isOn->getWoodPointer()->getGardenPointer()->setWeightsTotal(isOn->getWoodPointer()->getGardenPointer()->getWeightsTotal() + 1);
            }
        }
    }
}
void FRUIT_CLASS::fadeFruit() {
    if(weight > 0){
        weight--;
        if(isOn != NULL && isOn->getWeightsTotal() > 0) {
            isOn->setWeightsTotal((isOn->getWeightsTotal()) - 1);
            if (isOn->getWoodPointer() != NULL && isOn->getWoodPointer()->getWeightsTotal() > 0) {
                isOn->getWoodPointer()->setWeightsTotal(isOn->getWoodPointer()->getWeightsTotal() - 1);
                if (isOn->getWoodPointer()->getGardenPointer() != NULL && isOn->getWoodPointer()->getGardenPointer()->getWeightsTotal() > 0) {
                    isOn->getWoodPointer()->getGardenPointer()->setWeightsTotal(isOn->getWoodPointer()->getGardenPointer()->getWeightsTotal() - 1);
                }
            }
        }
    }
}
void FRUIT_CLASS::pluckFruit() {
    if(isOn != NULL){
        isOn->setWeightsTotal(isOn->getWeightsTotal() - weight);
        if (isOn->getWoodPointer() != NULL) {
            isOn->getWoodPointer()->setWeightsTotal(isOn->getWoodPointer()->getWeightsTotal() - weight);
            if (isOn->getWoodPointer()->getGardenPointer() != NULL) {
                isOn->getWoodPointer()->getGardenPointer()->setWeightsTotal(isOn->getWoodPointer()->getGardenPointer()->getWeightsTotal() - weight);
            }
        }
    }
    weight = 0;
}
FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS& other)
        : next(this), prev(this), weight(other.weight), length(other.length), isOn(NULL){
}

BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS &other)
        : next(this), prev(this), length(other.length), height(other.height),  fruitTotalAmount(other.fruitTotalAmount),
          fruitTotalWeight(other.fruitTotalWeight), isOn(NULL){
    if(fruitTotalAmount > 0) {
        firstFruit = new FRUIT_CLASS(*other.firstFruit);
        firstFruit->setBranch(this);
        FRUIT_CLASS *toCopyFruit = other.getFirst()->getNext();
        FRUIT_CLASS *currFruit = firstFruit;
        while (toCopyFruit != other.firstFruit) {
            FRUIT_CLASS *newFruit = new FRUIT_CLASS(*toCopyFruit);
            newFruit->setBranch(this);
            newFruit->setPrev(currFruit);
            newFruit->setNext(firstFruit);
            currFruit->setNext(newFruit);
            currFruit = newFruit;
            toCopyFruit = toCopyFruit->getNext();
        }
        firstFruit->setPrev(currFruit);
    }
}
WOOD_CLASS::WOOD_CLASS(const WOOD_CLASS &other)
        : next(this), prev(this), woodId(0), height(other.height),  branchesAmount(other.branchesAmount), fruitsAmount(other.fruitsAmount),
          weightsAmount(other.weightsAmount), isIn(NULL){
    if(branchesAmount > 0) {
        firstBranch = new BRANCH_CLASS(*other.firstBranch);
        firstBranch->setWoodPointer(this);

        BRANCH_CLASS *toCopyBranch = other.getFirst()->getNext();
        BRANCH_CLASS *currBranch = firstBranch;

        while (toCopyBranch != other.firstBranch) {
            BRANCH_CLASS *newBranch = new BRANCH_CLASS(*toCopyBranch);
            newBranch->setWoodPointer(this);
            newBranch->setPrev(currBranch);
            newBranch->setNext(firstBranch);
            currBranch->setNext(newBranch);
            currBranch = newBranch;
            toCopyBranch = toCopyBranch->getNext();
        }
        firstBranch->setPrev(currBranch);
    }
}

BRANCH_CLASS::BRANCH_CLASS(WOOD_CLASS *isOn, unsigned int height) {
    this->isOn = isOn;
    this->height = height;
    if(isOn != NULL) {
        if (isOn->getBranchesTotal() == 0) {
            isOn->setFirst(this);
            this->next = this;
            this->prev = this;
        } else {
            BRANCH_CLASS *prePrev = isOn->getFirst()->getPrev();//last branch
            prePrev->setNext(this);
            this->prev = prePrev;
            isOn->getFirst()->setPrev(this);
            this->next = isOn->getFirst();
        }
        isOn->setBranchesTotal(isOn->getBranchesTotal() + 1);
        if(isOn->getGardenPointer() != NULL) {
            isOn->getGardenPointer()->setBranchesTotal(isOn->getGardenPointer()->getBranchesTotal() + 1);
        }
    }else{
        this -> next = this;
        this -> prev = this;
    }
    length = 0;
    fruitTotalAmount = 0;
    fruitTotalWeight = 0;
    firstFruit = NULL;
}
BRANCH_CLASS::~BRANCH_CLASS(){
    if(isOn != NULL) {
        isOn->setBranchesTotal(isOn->getBranchesTotal() - 1);
        if (isOn->getGardenPointer() != NULL) {
            isOn->getGardenPointer()->setBranchesTotal(isOn->getGardenPointer()->getBranchesTotal() - 1);
        }
        if(this == isOn->getFirst() && isOn->getFirst() == isOn->getFirst()->getPrev()){
            next = NULL;
            prev = NULL;
            isOn->setFirst(NULL);
        }
        else{
            BRANCH_CLASS *newNext = this->getNext();
            BRANCH_CLASS *newPrev = this->getPrev();
            next->setPrev(newPrev);
            prev->setNext(newNext);
        }
    }
    if(fruitTotalAmount > 0) {
        FRUIT_CLASS *currFruit = firstFruit->getPrev();
        while (firstFruit != currFruit) {
            currFruit = currFruit->getPrev();
            delete currFruit->getNext();
        }
        delete currFruit;
    }
    length = 0;
    height = 0;
    fruitTotalAmount = 0;
    fruitTotalWeight = 0;
    firstFruit = NULL;
}
void BRANCH_CLASS::growthBranch() {
    length++;
    if (fruitTotalAmount > 0) {
        firstFruit->growthFruit();
        if (firstFruit->getNext() != firstFruit) {
            FRUIT_CLASS *currFruit = firstFruit->getNext();
            while (currFruit != firstFruit && currFruit != NULL) {
                currFruit->growthFruit();
                currFruit = currFruit->getNext();
            }
        }
    }
    if (length > 0 && length % 2 == 0) {
        FRUIT_CLASS *newFruit = new FRUIT_CLASS(length, this);
    }
}
void BRANCH_CLASS::fadeBranch() {
    if (length > 0) {
        if (fruitTotalAmount > 0) {
            if (firstFruit->getPrev()->getLength() == this->length) {
                if (firstFruit->getPrev() != firstFruit) {
                    delete firstFruit->getPrev();
                } else {
                    delete firstFruit;
                    this->firstFruit = NULL;
                }
            }
            if (fruitTotalAmount > 0) {
                firstFruit->fadeFruit();
                FRUIT_CLASS *currFruit = firstFruit;
                while (currFruit->getNext() != firstFruit) {
                    currFruit = currFruit->getNext();
                    currFruit->fadeFruit();
                }
            }
        }
        length--;
    }
}
void BRANCH_CLASS::harvestBranch(unsigned int minimalWeight) {
    if (fruitTotalAmount > 0) {
        FRUIT_CLASS *currFruit = firstFruit;
        if (currFruit->getWeight() >= minimalWeight) {
            currFruit->pluckFruit();
        }
        if(firstFruit->getNext() != firstFruit) {
            while (currFruit->getNext() != firstFruit) {
                currFruit = currFruit->getNext();
                if (currFruit->getWeight() >= minimalWeight) {
                    currFruit->pluckFruit();
                }
            }
        }
    }
}
void BRANCH_CLASS::cutBranch(unsigned int newLength) {
    if (fruitTotalAmount > 0 && length > 0) {
        FRUIT_CLASS *currFruit = firstFruit->getPrev();
        while (currFruit->getLength() > newLength) {
            FRUIT_CLASS *toDelete = currFruit;
            if(currFruit->getPrev() != currFruit){
                currFruit = currFruit->getPrev();
                if(toDelete != NULL){
                    delete toDelete;
                    toDelete= NULL;
                }
            }else {
                delete firstFruit;
                firstFruit = NULL;
                break;
            }
        }
    }
    length = newLength;
}
FRUIT_CLASS *BRANCH_CLASS::getFruitPointer(unsigned int fruitOnLength) {
    FRUIT_CLASS *pointer = NULL;
    if(fruitTotalAmount > 0) {
        FRUIT_CLASS *currFruit = firstFruit;
        bool found = 0;
        while (currFruit != firstFruit->getPrev()) {
            if (currFruit->getLength() == fruitOnLength) {
                pointer = currFruit;
                found = 1;
                break;
            }
            currFruit = currFruit->getNext();
        }
        if (currFruit->getLength() == fruitOnLength && found == 0) {
            pointer = currFruit;
        }
    }
    return pointer;
}

WOOD_CLASS::WOOD_CLASS(unsigned int woodId, GARDEN_CLASS *isIn, bool isLast) {
    this->woodId = woodId;
    this->isIn = isIn;
    if(isIn != NULL){
        if (isIn->getWoodsTotal() == 0) {
            isIn->setFirst(this);
            this->next = this;
            this->prev = this;
        } else if(isLast){
            WOOD_CLASS *prePrev = isIn->getFirst()->getPrev();//last branch
            prePrev->setNext(this);
            this->prev = prePrev;
            isIn->getFirst()->setPrev(this);
            this->next = isIn->getFirst();
        }else{
            this->next = NULL;
            this->prev = NULL;
        }
        isIn->setWoodsTotal(isIn->getWoodsTotal() + 1);
    }
    else{
        this -> next = this;
        this -> prev = this;
    }
    height = 0;
    branchesAmount = 0;
    fruitsAmount = 0;
    weightsAmount = 0;
    firstBranch = NULL;
}
WOOD_CLASS::~WOOD_CLASS() {
    if(isIn != NULL){
        if(isIn->getWoodsTotal() > 0) {
            isIn->setWoodsTotal(isIn->getWoodsTotal() - 1);
        }
        if(this == isIn->getFirst() && isIn->getFirst() == isIn->getFirst()->getPrev()){
            next = NULL;
            prev = NULL;
            isIn->setFirst(NULL);
        }
        else{
            WOOD_CLASS *newNext = this->getNext();
            WOOD_CLASS *newPrev = this->getPrev();
            next->setPrev(newPrev);
            prev->setNext(newNext);
        }
    }
    if(branchesAmount > 0){
        BRANCH_CLASS *currBranch = firstBranch->getPrev();
        while (firstBranch != currBranch) {
            currBranch = currBranch->getPrev();
            delete currBranch->getNext();
        }
        delete currBranch;
    }
    firstBranch = NULL;
}
void WOOD_CLASS::growthWood() {
    height++;
    if (branchesAmount > 0) {
        BRANCH_CLASS *currBranch = firstBranch;
        currBranch->growthBranch();
        while (currBranch->getNext() != firstBranch) {
            currBranch = currBranch->getNext();
            currBranch->growthBranch();
        }
    }
    if (height > 0 && height % 3 == 0) {
        BRANCH_CLASS *newBranch = new BRANCH_CLASS(this, height);
    }
}
void WOOD_CLASS::fadeWood() {
    if (height > 0) {
        if (branchesAmount > 0) {
            if (firstBranch->getPrev()->getHeight() == this->height) {
                if (firstBranch->getPrev() != firstBranch) {
                    BRANCH_CLASS *lastBranch = firstBranch->getPrev();
                    BRANCH_CLASS *preLast = lastBranch->getPrev();
                    delete lastBranch;
                    firstBranch->setPrev(preLast);
                    preLast->setNext(firstBranch);
                } else {
                    delete firstBranch;
                    this->firstBranch = NULL;
                }
            }
            if (branchesAmount > 0) {
                firstBranch->fadeBranch();
                BRANCH_CLASS *currBranch = firstBranch;
                while (currBranch->getNext() != firstBranch) {
                    currBranch = currBranch->getNext();
                    currBranch->fadeBranch();
                }
            }
        }
        height--;
    }
}
void WOOD_CLASS::harvestWood(unsigned int minimalWeight) {
    if (branchesAmount > 0) {
        BRANCH_CLASS *currBranch = firstBranch;
        currBranch->harvestBranch(minimalWeight);
        currBranch = currBranch->getNext();
        while (currBranch != firstBranch) {
            currBranch->harvestBranch(minimalWeight);
            currBranch = currBranch->getNext();
        }
    }
}
void WOOD_CLASS::cutWood(unsigned int newHeight) {
    if(newHeight < this->height) {
        if (branchesAmount > 0) {
            BRANCH_CLASS *currBranch = firstBranch->getPrev();
            while (currBranch->getHeight() > newHeight) {
                currBranch->cutBranch(0);
                BRANCH_CLASS *toDelete = currBranch;
                if(currBranch == currBranch->getPrev()){
                    delete toDelete;
                    break;
                }else {
                    currBranch = currBranch->getPrev();
                    delete toDelete;
                    currBranch->setNext(firstBranch);
                    firstBranch->setPrev(currBranch);
                }
            }
        }
        height = newHeight;
    }
}

void WOOD_CLASS::cloneBranch(BRANCH_CLASS *toClone) {
    if(branchesAmount > 0 && toClone != NULL && toClone->getLength() != 0) {
        if(firstBranch->getLength() == 0){
            BRANCH_CLASS* clone = new BRANCH_CLASS(*toClone);
            clone->setWoodPointer(this);
            clone->setHeight(firstBranch->getHeight());
            clone->setPrev(firstBranch->getPrev());
            firstBranch->getPrev()->setNext(clone);
            clone->setNext(firstBranch->getNext());
            firstBranch->getNext()->setPrev(clone);
            BRANCH_CLASS* toDel = firstBranch;
            firstBranch = clone;
            toDel->setWoodPointer(NULL);
            delete toDel;
            weightsAmount = weightsAmount + clone->getWeightsTotal();
            fruitsAmount = fruitsAmount + clone->getFruitsTotal();
            if (isIn != NULL) {
                isIn->setWeightsTotal(isIn->getWeightsTotal() + clone->getWeightsTotal());
                isIn->setFruitsTotal(isIn->getFruitsTotal() + clone->getFruitsTotal());
            }
        }else{
            BRANCH_CLASS *currBranch = firstBranch;
            while (currBranch->getLength() != 0 && currBranch != firstBranch->getPrev()) {
                currBranch = currBranch->getNext();
            }
            if (currBranch->getLength() == 0) {
                BRANCH_CLASS* clone = new BRANCH_CLASS(*toClone);
                clone->setWoodPointer(this);
                clone->setHeight(currBranch->getHeight());
                clone->setPrev(currBranch->getPrev());
                currBranch->getPrev()->setNext(clone);
                clone->setNext(currBranch->getNext());
                currBranch->getNext()->setPrev(clone);
                weightsAmount = weightsAmount + clone->getWeightsTotal();
                fruitsAmount = fruitsAmount + clone->getFruitsTotal();
                currBranch->setWoodPointer(NULL);
                delete currBranch;
                if (isIn != NULL) {
                    isIn->setWeightsTotal(isIn->getWeightsTotal() + clone->getWeightsTotal());
                    isIn->setFruitsTotal(isIn->getFruitsTotal() + clone->getFruitsTotal());
                }
            }
            else if(currBranch->getNext()->getLength() == 0){
                BRANCH_CLASS* clone = new BRANCH_CLASS(*toClone);
                clone->setWoodPointer(this);
                clone->setHeight(currBranch->getHeight());
                clone->setPrev(currBranch->getPrev());
                currBranch->getPrev()->setNext(clone);
                clone->setNext(currBranch->getNext());
                currBranch->getNext()->setPrev(clone);
                weightsAmount = weightsAmount + clone->getWeightsTotal();
                fruitsAmount = fruitsAmount + clone->getFruitsTotal();
                currBranch->setWoodPointer(NULL);
                delete currBranch;
                if (isIn != NULL) {
                    isIn->setWeightsTotal(isIn->getWeightsTotal() + clone->getWeightsTotal());
                    isIn->setFruitsTotal(isIn->getFruitsTotal() + clone->getFruitsTotal());
                }
            }
        }
    }
}
void WOOD_CLASS::setBranchesTotal(unsigned int i) {
    this->branchesAmount = i;
}
BRANCH_CLASS *WOOD_CLASS::getBranchPointer(unsigned int heightOfBranch) {
    BRANCH_CLASS *pointer = NULL;
    if(branchesAmount > 0) {
        BRANCH_CLASS *currBranch = firstBranch;
        bool found = 0;
        while (currBranch != firstBranch->getPrev()) {
            if (currBranch->getHeight() == heightOfBranch) {
                pointer = currBranch;
                found = 1;
                break;
            }
            currBranch = currBranch->getNext();
        }
        if (currBranch->getHeight() == heightOfBranch && found == 0) {
            pointer = currBranch;
        }
    }
    return pointer;
}

void GARDEN_CLASS::plantWood() {
    if (woodTotalAmount > 0) {
        if (firstWood->getPrev()->getNumber() + 1 == woodTotalAmount) {
            unsigned int newId = firstWood->getPrev()->getNumber() + 1;
            WOOD_CLASS *newWood = new WOOD_CLASS(newId, this);
        }
        else {
            WOOD_CLASS* currWood = firstWood;
            WOOD_CLASS* woodSpot = NULL;
            if(firstWood->getNumber() != 0){
                unsigned int newId = 0;
                WOOD_CLASS *prePrev = firstWood->getPrev();
                WOOD_CLASS *newWood = new WOOD_CLASS(newId, this, false);
                newWood->setNext(firstWood);
                firstWood->setPrev(newWood);
                newWood->setPrev(prePrev);
                prePrev->setNext(newWood);
                firstWood = newWood;
            }
            else {
                while (currWood != firstWood->getPrev()) {
                    if (currWood->getNext()->getNumber() - currWood->getNumber() > 1) {
                        woodSpot = currWood;
                        break;
                    }
                    currWood = currWood->getNext();
                }
                unsigned int newId = woodSpot->getNumber() + 1;
                WOOD_CLASS *preNext = woodSpot->getNext();
                WOOD_CLASS *newWood = new WOOD_CLASS(newId, this, false);
                newWood->setNext(preNext);
                preNext->setPrev(newWood);
                newWood->setPrev(woodSpot);
                woodSpot->setNext(newWood);
            }
        }
    } else {
        WOOD_CLASS* newWood = new WOOD_CLASS(0, this);
    }
}
void GARDEN_CLASS::extractWood(unsigned int toExtractId) {
    if(woodTotalAmount > 0) {
        WOOD_CLASS *currWood = firstWood->getPrev();
        if(currWood->getNumber() == toExtractId){
            delete currWood;
        }
        else{
            while (currWood->getNumber() > toExtractId) {
                if (currWood == firstWood) {
                    break;
                }
                currWood = currWood->getPrev();
            }
            if (currWood->getNumber() == toExtractId) {
                if(currWood == firstWood){
                    firstWood = currWood->getNext();
                }
                delete currWood;
            }
        }
    }
}
void GARDEN_CLASS::cloneWood(unsigned int toCloneId) {
    if(woodTotalAmount > 0) {
        WOOD_CLASS *toCloneWood = firstWood;
        bool foundToClone = 0;
        bool foundSpot = 0;
        while (toCloneWood->getNumber() <= toCloneId) {
            if (toCloneWood->getNumber() == toCloneId) {
                foundToClone = 1;
                break;
            }
            if (toCloneWood->getNext() == firstWood) {
                break;
            }
            toCloneWood = toCloneWood->getNext();
        }
        if (foundToClone == 1) {
            WOOD_CLASS* currWood = firstWood;
            WOOD_CLASS* woodSpot = NULL;
            if(firstWood->getNumber() != 0){
                unsigned int newId = 0;
                WOOD_CLASS *prePrev = firstWood->getPrev();
                WOOD_CLASS *newWood = new WOOD_CLASS(*toCloneWood);
                newWood->setGarden(this);
                newWood->setNumber(newId);
                newWood->setNext(firstWood);
                firstWood->setPrev(newWood);
                newWood->setPrev(prePrev);
                prePrev->setNext(newWood);
                firstWood = newWood;
            }else {
                while (currWood != firstWood->getPrev()) {
                    if (currWood->getNext()->getNumber() - currWood->getNumber() > 1) {
                        woodSpot = currWood;
                        break;
                    }
                    currWood = currWood->getNext();
                }
                if (woodSpot == NULL) {
                    WOOD_CLASS *preLast = firstWood->getPrev();
                    unsigned int newId = firstWood->getPrev()->getNumber() + 1;
                    WOOD_CLASS *newWood = new WOOD_CLASS(*toCloneWood);
                    newWood->setGarden(this);
                    newWood->setNumber(newId);
                    newWood->setPrev(preLast);
                    newWood->setNext(firstWood);
                    preLast->setNext(newWood);
                    firstWood->setPrev(newWood);
                } else {
                    unsigned int newId = woodSpot->getNumber() + 1;
                    WOOD_CLASS *prePrev = woodSpot->getPrev();
                    WOOD_CLASS *newWood = new WOOD_CLASS(*toCloneWood);
                    newWood->setNumber(newId);
                    newWood->setGarden(this);
                    newWood->setNext(woodSpot);
                    woodSpot->setPrev(newWood);
                    newWood->setPrev(prePrev);
                    prePrev->setNext(newWood);
                }
            }
            setWeightsTotal(weightsTotalAmount + toCloneWood->getWeightsTotal());
            setFruitsTotal(fruitsTotalAmount + toCloneWood->getFruitsTotal());
            setBranchesTotal(branchesTotalAmount + toCloneWood->getBranchesTotal());
            setWoodsTotal(woodTotalAmount + 1);
        }
    }
}
void GARDEN_CLASS::growthGarden() {
    if(woodTotalAmount > 0) {
        WOOD_CLASS *currWood = firstWood;
        while (currWood != firstWood->getPrev()) {
            currWood->growthWood();
            currWood = currWood->getNext();
        }
        currWood->growthWood();
    }
}
void GARDEN_CLASS::fadeGarden() {
    if (woodTotalAmount > 0) {
        WOOD_CLASS *currWood = firstWood;
        while (currWood != firstWood->getPrev()) {
            currWood->fadeWood();
            currWood = currWood->getNext();
        }
        currWood->fadeWood();
    }
}
void GARDEN_CLASS::harvestGarden(unsigned int minimalWeight) {
    if(woodTotalAmount > 0) {
        WOOD_CLASS *currWood = firstWood;
        while (currWood != firstWood->getPrev()) {
            currWood->harvestWood(minimalWeight);
            currWood = currWood->getNext();
        }
        currWood->harvestWood(minimalWeight);
    }
}
WOOD_CLASS *GARDEN_CLASS::getWoodPointer(unsigned int woodId) {
    WOOD_CLASS *pointer = NULL;
    if(woodTotalAmount > 0) {
        WOOD_CLASS *currWood = firstWood;
        bool found = 0;
        while (currWood != firstWood->getPrev()) {
            if (currWood->getNumber() == woodId) {
                pointer = currWood;
                found = 1;
                break;
            }
            currWood = currWood->getNext();
        }
        if (currWood->getNumber() == woodId && found == 0) {
            pointer = currWood;
        }
    }
    return pointer;
}
void GARDEN_CLASS::setWeightsTotal(unsigned int i) {
    this->weightsTotalAmount = i;
}
