#include <stdio.h>
#include <stdbool.h>

typedef struct residence {
    int residents, residenceConsumption, consumptionPerResident;
}residence;

typedef struct city {
    int id, totalResidents, totalConsumption;
    residence residences[100];
    double averageConsumptionPerResident;
}city;

int main() {
    int numberOfResidences;
    scanf("%d", &numberOfResidences);

    for(int cityCount = 1; numberOfResidences != 0; cityCount++){
        city currentCity;
        currentCity.totalResidents = 0;
        currentCity.totalConsumption = 0;
        int residents, residenceConsumption, consumptionPerResident;

        bool isGhost;
        for(int i = 0; i < numberOfResidences; i++){
            isGhost = false;
            scanf("%d%d", &residents, &residenceConsumption);
            consumptionPerResident = residenceConsumption / residents;

            for(int j = 0; j < i; j++){
                // if there is a residence with the same consumptionPerResident as the current one.
                // we do not create another residence, but rather add to the already existing one the ammount of residents from the current.
                // besides that we need to add to the total residents and total consumption variables of the city.
                if(consumptionPerResident == currentCity.residences[j].consumptionPerResident) {
                    currentCity.residences[j].residents += residents;
                    currentCity.totalResidents += residents;
                    currentCity.totalConsumption += residenceConsumption;
                    numberOfResidences--;
                    i--;
                    isGhost = true;
                }
            }

            // if there isn't a residence with the same consumptionPerResident as the current one.
            if(!isGhost){
                currentCity.residences[i].residents = residents;
                currentCity.residences[i].residenceConsumption = residenceConsumption;
                currentCity.residences[i].consumptionPerResident = consumptionPerResident;
                currentCity.totalResidents += currentCity.residences[i].residents;
                currentCity.totalConsumption += currentCity.residences[i].residenceConsumption;
            }
            
        }
        
        currentCity.id = cityCount;
        // Weird way of making this calculation but the only one that works. Otherwise the answers will be .01 off for some reason.
        currentCity.averageConsumptionPerResident = ((100 * currentCity.totalConsumption) / currentCity.totalResidents) / 100.0;
        

        // Sort (Insertion Sort)
        int y, z;
        residence x;
        for(y = 1; y < numberOfResidences; y++){
            x = currentCity.residences[y];
            for(z = y - 1; z >= 0 && currentCity.residences[z].consumptionPerResident > x.consumptionPerResident; z--){
                currentCity.residences[z + 1] = currentCity.residences[z];
            }
            currentCity.residences[z + 1] = x;
        }

        // Print
        printf("Cidade# %d:\n", cityCount);
        for(int i = 0; i < numberOfResidences; i++){
            // if it's the last residence, do not add an empty space at the end, but a new line.
            if(i == numberOfResidences - 1){
                printf("%d-%d\n", currentCity.residences[i].residents, currentCity.residences[i].consumptionPerResident);
            } else {
                printf("%d-%d ", currentCity.residences[i].residents, currentCity.residences[i].consumptionPerResident);
            }
        }
        printf("Consumo medio: %.2f m3.\n", currentCity.averageConsumptionPerResident);
        printf("\n");
        scanf("%d", &numberOfResidences);
    }

    return 0;
}

/*
Cidade# 1:
10-15
Consumo medio: 15.60 m3.

Cidade# 2:
10-17
Consumo medio: 17.90 m3.

Cidade# 3:
10-18
Consumo medio: 18.80 m3.


Cidade# 1:
2-5 3-7 3-13
Consumo medio: 9.00 m3.

Cidade# 2:
5-10 6-11 2-20 1-25
Consumo medio: 13.28 m3.

Cidade# 1:
5-10 6-11 2-20 1-25
Consumo medio: 13.28 m3.


#include <stdio.h>

struct residence {
    int residents, residenceConsumption, consumptionPerResident;
};

struct city {
    int id, totalResidents = 0, totalConsumption = 0;
    residence residences[100];
    double averageConsumptionPerResident;
};

int main() {
    int numberOfResidences;
    scanf("%d", &numberOfResidences);

    for(int cityCount = 1; numberOfResidences != 0; cityCount++){
        city currentCity;
        int residents, residenceConsumption, consumptionPerResident;

        bool isGhost;
        for(int i = 0; i < numberOfResidences; i++){
            isGhost = false;
            scanf("%d%d", &residents, &residenceConsumption);
            consumptionPerResident = residenceConsumption / residents;

            for(int j = 0; j < i; j++){
                // if there is a residence with the same consumptionPerResident as the current one.
                // we do not create another residence, but rather add to the already existing one the ammount of residents from the current.
                // besides that we need to add to the total residents and total consumption variables of the city.
                if(consumptionPerResident == currentCity.residences[j].consumptionPerResident) {
                    currentCity.residences[j].residents += residents;
                    currentCity.totalResidents += residents;
                    currentCity.totalConsumption += residenceConsumption;
                    numberOfResidences--;
                    i--;
                    isGhost = true;
                }
            }

            // if there isn't a residence with the same consumptionPerResident as the current one.
            if(!isGhost){
                currentCity.residences[i].residents = residents;
                currentCity.residences[i].residenceConsumption = residenceConsumption;
                currentCity.residences[i].consumptionPerResident = consumptionPerResident;
                currentCity.totalResidents += currentCity.residences[i].residents;
                currentCity.totalConsumption += currentCity.residences[i].residenceConsumption;
            }
            
        }
        
        currentCity.id = cityCount;
        // Weird way of making this calculation but the only one that works. Otherwise the answers will be .01 off for some reason.
        currentCity.averageConsumptionPerResident = ((100 * currentCity.totalConsumption) / currentCity.totalResidents) / 100.0;
        

        // Sort (Insertion Sort)
        int y, z;
        residence x;
        for(y = 1; y < numberOfResidences; y++){
            x = currentCity.residences[y];
            for(z = y - 1; z >= 0 && currentCity.residences[z].consumptionPerResident > x.consumptionPerResident; z--){
                currentCity.residences[z + 1] = currentCity.residences[z];
            }
            currentCity.residences[z + 1] = x;
        }

        // Print
        printf("Cidade# %d:\n", cityCount);
        for(int i = 0; i < numberOfResidences; i++){
            // if it's the last residence, do not add an empty space at the end, but a new line.
            if(i == numberOfResidences - 1){
                printf("%d-%d\n", currentCity.residences[i].residents, currentCity.residences[i].consumptionPerResident);
            } else {
                printf("%d-%d ", currentCity.residences[i].residents, currentCity.residences[i].consumptionPerResident);
            }
        }
        printf("Consumo medio: %.2f m3.\n", currentCity.averageConsumptionPerResident);
        printf("\n");
        scanf("%d", &numberOfResidences);
    }

    return 0;
}

*/