#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 6

struct package
{
    char* id;
    int weight;
};

typedef struct package package;

struct post_office
{
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town
{
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for (int count = 0; count < t.offices_count; count++) {
        printf("\t%i:\n", count);
        for (int c = 0; c < (t.offices)[count].packages_count; c++) {
            printf("\t\t%s\n", ((((t.offices)[count]).packages)[c]).id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    int min, max, weight, x = 0;

    while (x < (*source).offices[source_office_index].packages_count) {
        weight = (*source).offices[source_office_index].packages[x].weight;
        min = (*target).offices[target_office_index].min_weight;
        max = (*target).offices[target_office_index].max_weight;
        if (weight >= min && weight <= max) {
            int target_count = (*target).offices[target_office_index].packages_count;
            (*target).offices[target_office_index].packages = (package*) realloc((*target).offices[target_office_index].packages, sizeof(package)*(target_count+1));
            (*target).offices[target_office_index].packages[target_count] = (*source).offices[source_office_index].packages[x];
            (*target).offices[target_office_index].packages_count++;

            for (int y = x; y < (*source).offices[source_office_index].packages_count - 1; y++)
                (*source).offices[source_office_index].packages[y] = (*source).offices[source_office_index].packages[y+1];
            
            int source_count = (*source).offices[source_office_index].packages_count;
            (*source).offices[source_office_index].packages = (package*) realloc((*source).offices[source_office_index].packages, sizeof(package)*(source_count-1));
            (*source).offices[source_office_index].packages_count--;
        }
        else {
            x++;
        }
    }
    return;
}

town town_with_most_packages(town* towns, int towns_count) {
    town t;
    int all_package_count = 0;
    int town_packages_count = 0;
    for (int c = 0; c < towns_count; c++) {
        for (int d = 0; d < towns[c].offices_count; d++) {
            town_packages_count += towns[c].offices[d].packages_count;
        }
        if (town_packages_count > all_package_count) {
            all_package_count = town_packages_count;
            t = towns[c];
        }
        town_packages_count = 0;
    }
    return t;
}

town* find_town(town* towns, int towns_count, char* name) {
    int c;
    for (c = 0; c < towns_count; c++)
        if (!strcmp(towns[c].name, name))
            break;
    return (towns + c);
}

int main()
{
    int towns_count;
    scanf("%d", &towns_count);
    town* towns = malloc(sizeof(town)*towns_count);
    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }
    int queries;
    scanf("%d", &queries);
    char town_name[MAX_STRING_LENGTH];
    while (queries--) {
        int type;
        scanf("%d", &type);
        switch (type) {
        case 1:
            scanf("%s", town_name);
            town* t = find_town(towns, towns_count, town_name);
            print_all_packages(*t);
            break;
        case 2:
            scanf("%s", town_name);
            town* source = find_town(towns, towns_count, town_name);
            int source_index;
            scanf("%d", &source_index);
            scanf("%s", town_name);
            town* target = find_town(towns, towns_count, town_name);
            int target_index;
            scanf("%d", &target_index);
            send_all_acceptable_packages(source, source_index, target, target_index);
            break;
        case 3:
            printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
            break;
        }
    }
    return 0;
}