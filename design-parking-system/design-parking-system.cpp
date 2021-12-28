class ParkingSystem {
private:
    int bMax, mMax, sMax;
    int b = 0;
    int m = 0;
    int s = 0;
public:
    ParkingSystem(int big, int medium, int small) {
        bMax = big;
        mMax = medium;
        sMax = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1 && b < bMax) {
            b++;
            return true;
        }
        else if (carType == 2 && m < mMax) {
            m++;
            return true;
        }
        else if (carType == 3 && s < sMax) {
            s++;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */