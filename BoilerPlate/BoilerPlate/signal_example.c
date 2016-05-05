//
//  signal_example.c
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 5/5/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "signal_example.h"

static void catch_function(int signo){
    puts("Interactive signal caught!");
}

int test_signal() {
    
    if(signal(SIGINT ,catch_function)==SIG_ERR){
        fputs("Error occured while setting signal handler\n",
              stderr);
        return EXIT_FAILURE;
    }
    
    puts("Raising interactive attention signal\n");
    
    if(raise(SIGINT)!=0){
        fputs("Error rasining signal\n", stderr);
        return EXIT_FAILURE;
    }
    puts("Exiting");
    
    return EXIT_SUCCESS;

}