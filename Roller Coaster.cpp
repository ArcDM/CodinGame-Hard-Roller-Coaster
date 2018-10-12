#include <iostream>

/**This program takes an input that includes
 * the number of people in a number of groups
 * and outputs the number of people that rode the ride that day
 **/

struct Group
{
    Group* next_set; // skip to next set
    int group_count, set_count = NULL; // number in group, saved calculation for ride
};

int main()
{
    int seat_count, max_rides, group_count;
    
    std::cin >> seat_count >> max_rides >> group_count; std::cin.ignore();
    
    Group groups[ group_count ];
    
    for( Group &input_group: groups )
    { // populating groups
        std::cin >> input_group.group_count; std::cin.ignore();
    }
    
    Group* group_iterator = groups;
    long long people_count = 0;
    
    for( size_t ride_count = max_rides; ride_count; --ride_count )
    { // for all rides in the day
        if( group_iterator->set_count )
        { // use the saved number
            people_count += group_iterator->set_count; // pre counted
            group_iterator = group_iterator->next_set; // jump to the group after these
        }
        else
        { // if the set has not been calculated
            int people_on_ride = 0;
            Group* set_pointer = group_iterator; // set_pointer keeps the program from counting people twice
            
            while( people_on_ride + group_iterator->group_count <= seat_count )
            { // count out groups until the ride is full
                people_on_ride += group_iterator->group_count;
            
                if( ++group_iterator == groups + group_count )
                { // loop the iterator to the front
                    group_iterator = groups;
                }
            
                if( set_pointer == group_iterator )
                { // all groups are on the ride
                    break;
                }
            }
        
            set_pointer->set_count = people_on_ride; // saved calculation
            set_pointer->next_set = group_iterator; // saved next set of groups
            people_count += people_on_ride;
        }
    }

    std::cout << people_count << std::endl;
}