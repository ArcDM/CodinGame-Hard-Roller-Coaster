"""
    This program takes an input that includes the
    number of people in a number of groups and outputs
    the number of people that rode the ride that day
"""

class Group:
    def __init__( self, input_count ):
        self.group_count = input_count
        self.set_count = None

ride_seats, maximum_ride_count, group_count = ( int( input_data ) for input_data in input().split() )
groups = [ None ] * group_count

for index in range( group_count ): # populating groups
    groups[ index ] = Group( int( input() ) )
    
people_ridden_count = 0
index = 0

for ride_count in range( maximum_ride_count ): # for all rides in the day
    if groups[ index ].set_count: # if the set already been calculated
        people_ridden_count += groups[ index ].set_count  # use the saved number
        index = groups[ index ].next_set # jump to the group after these
    else:
        people_on_ride = 0
        saved_index = index # keeps the program from counting people twice
        
        # count out groups until the ride is full
        while people_on_ride + groups[ index ].group_count <= ride_seats:
            people_on_ride += groups[ index ].group_count
            index = ( index + 1 ) % len( groups ) # circularizes the groups list
        
            if saved_index == index: # all groups are on the ride
                break
        
        # save calculation and next set of groups
        groups[ saved_index ].set_count = people_on_ride
        groups[ saved_index ].next_set = index
        people_ridden_count += people_on_ride

print( people_ridden_count )