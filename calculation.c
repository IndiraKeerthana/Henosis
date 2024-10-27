#include <stdio.h>

#define TREE_SEQUESTRATION_RATE 22.0 // kg CO2 absorbed by one tree per year

// Function to calculate total carbon emissions
float calculateEmissions(float industryEmissions, float transportEmissions, float fuelEmissions, float rawMaterialEmissions) {
    return industryEmissions + transportEmissions + fuelEmissions + rawMaterialEmissions;
}

// Function to calculate the number of trees needed to offset emissions
int calculateTreesNeeded(float totalEmissions) {
    return (int)(totalEmissions / TREE_SEQUESTRATION_RATE) + 1; // Round up
}

int main() {
    float industryEmissions, transportEmissions, fuelEmissions, rawMaterialEmissions;

    // Input emissions from various sources
    printf("Enter the carbon emissions from industrial processes (in kg): ");
    scanf("%f", &industryEmissions);

    printf("Enter the carbon emissions from transportation (in kg): ");
    scanf("%f", &transportEmissions);

    printf("Enter the carbon emissions from fuel consumption (in kg): ");
    scanf("%f", &fuelEmissions);

    printf("Enter the carbon emissions from raw material usage (in kg): ");
    scanf("%f", &rawMaterialEmissions);

    // Calculate total emissions
    float totalEmissions = calculateEmissions(industryEmissions, transportEmissions, fuelEmissions, rawMaterialEmissions);
    printf("\nTotal Carbon Footprint: %.2f kg CO2\n", totalEmissions);

    // Calculate the number of trees needed
    int treesNeeded = calculateTreesNeeded(totalEmissions);
    printf("To offset the total carbon footprint, you need to plant approximately %d trees.\n", treesNeeded);

    return 0;
}

