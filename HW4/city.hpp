//
//  city.hpp
//  CS776_HW4
//
//  Created by Sierra Gonzales on 10/3/17.
//  Copyright © 2017 Sierra Gonzales. All rights reserved.
//

#ifndef city_hpp
#define city_hpp

#include <stdio.h>


class city {
    friend class Policy;
    friend class EA;
    friend class Parameters;
    
    double x;
    double y;
    int origin;
    
};


#endif /* city_hpp */
