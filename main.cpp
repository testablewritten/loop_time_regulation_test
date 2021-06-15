#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

void Test(){
    std::cout <<"hello world" << std::endl;
}

 

int main(){

    while(1){

        std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

        Test();

        std::chrono::system_clock::time_point compute_end = std::chrono::system_clock::now();
        std::chrono::duration<double> default_compute_elapsed = compute_end-start;
        std::chrono::microseconds compute_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(default_compute_elapsed);

        //loop frequency regulation
        std::this_thread::sleep_for(std::chrono::microseconds(1000-compute_elapsed.count()));

        std::chrono::system_clock::time_point loop_end = std::chrono::system_clock::now();
        std::chrono::duration<double> default_loop_elapsed = loop_end-start;
        std::chrono::microseconds loop_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(default_loop_elapsed);

        std::cout <<"compute time: " << compute_elapsed.count()<<" microsec " << "   loop time: "<< loop_elapsed.count()<< " microsec " <<std::endl; 

        std::chrono::microseconds micro = std::chrono::duration_cast<std::chrono::microseconds>(default_loop_elapsed);
        std::chrono::milliseconds mill  = std::chrono::duration_cast<std::chrono::milliseconds>(default_loop_elapsed);
        std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(default_loop_elapsed);
        std::chrono::minutes min = std::chrono::duration_cast<std::chrono::minutes>(default_loop_elapsed);
        std::chrono::hours hour = std::chrono::duration_cast<std::chrono::hours>(default_loop_elapsed);

        std::cout << "default " << default_loop_elapsed.count() << " default" << std::endl;
        std::cout << "microsec : " << micro.count() << " microseconds" << std::endl;
        std::cout << "millisec : " << mill.count() << " milliseconds" << std::endl;
        std::cout << "sec : " << sec.count() << " seconds" << std::endl;
        std::cout << "min : " << min.count() << " minutes" << std::endl;
        std::cout << "hour : " << hour.count() << " hour" << std::endl <<std::endl;
    }

    return 0;
}
