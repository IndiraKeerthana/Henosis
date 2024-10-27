#include <stdio.h>

#define TREE_SEQUESTRATION_RATE 22.0 // Average kg CO2 absorbed per tree per year

// Function to calculate transportation emissions
float calculate_transportation_emissions(float distance, char mode) {
    float emission_factor;
    switch (mode) {
        case 'C': // Car
            emission_factor = 2.31; // kg CO2 per mile for car
            break;
        case 'B': // Bus
            emission_factor = 0.89; // kg CO2 per mile for bus
            break;
        default:
            printf("Invalid mode of transport\n");
            return 0;
    }
    return distance * emission_factor;
}

// Function to calculate emissions from fossil fuel burning
float calculate_fuel_emissions(float fuel_consumed) {
    return fuel_consumed * 2.31; // kg CO2 per liter of fossil fuel burned
}

// Function to calculate emissions from raw material consumption
float calculate_raw_material_emissions(float raw_material_used) {
    return raw_material_used * 3.0; // kg CO2 per kg of raw material used
}

// Function to calculate number of trees needed to offset carbon emissions
int calculate_trees_needed(float total_emissions) {
    return (int)(total_emissions / TREE_SEQUESTRATION_RATE + 0.5); // rounding to nearest whole number
}

int main() {
    float distance, fuel_consumed, raw_material_used;
    char transport_mode;
    float transport_emissions, fuel_emissions, raw_material_emissions, total_emissions;
    int trees_needed;

    // Input for transportation details
    printf("Enter distance traveled (in miles): ");
    scanf("%f", &distance);
    printf("Enter mode of transport (C for Car, B for Bus): ");
    scanf(" %c", &transport_mode);

    // Input for fossil fuel consumption
    printf("Enter fuel consumed (in liters): ");
    scanf("%f", &fuel_consumed);

    // Input for raw material consumption
    printf("Enter raw material used (in kg): ");
    scanf("%f", &raw_material_used);

    // Calculating emissions
    transport_emissions = calculate_transportation_emissions(distance, transport_mode);
    fuel_emissions = calculate_fuel_emissions(fuel_consumed);
    raw_material_emissions = calculate_raw_material_emissions(raw_material_used);

    total_emissions = transport_emissions + fuel_emissions + raw_material_emissions;

    // Calculating the number of trees needed to offset the carbon emissions
    trees_needed = calculate_trees_needed(total_emissions);

    // Output the results
    printf("Transportation Emissions: %.2f kg CO2\n", transport_emissions);
    printf("Fuel Emissions: %.2f kg CO2\n", fuel_emissions);
    printf("Raw Material Emissions: %.2f kg CO2\n", raw_material_emissions);
    printf("Total Carbon Footprint: %.2f kg CO2\n", total_emissions);
    printf("To offset this carbon footprint, you need to plant approximately %d trees.\n", trees_needed);

    return 0;
}

