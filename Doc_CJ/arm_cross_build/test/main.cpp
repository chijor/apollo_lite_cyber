/**
 * Serial port example.
 * Compile with: g++ main.cpp -lpthread -o main
 * 
 * Cymait http://cymait.com
 **/
  
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <termios.h>

#include <atomic>
#include <memory>
#include <vector>
#include "json/json.hpp"

using json = nlohmann::json;

int main(int argc, char** argv) 
{
   std::vector<int> tv;
   tv.push_back(1); 
   tv.push_back(2); 
   tv.push_back(3);
   for(auto it : tv)
   {
      std::cout<< it << std::endl;
   } 
   FILE *fp = fopen(argv[1],"r");
    if(!fp)
    {
        return false;
    }

    fseek(fp, 0, SEEK_END);
    int length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char * buffer = new char[length + 1];
    memset(buffer, 0, length + 1);

    fread(buffer, length, 1, fp);
    fclose(fp);

    json root = json::parse(buffer);
    json features = root["features"];
    for(auto feature : features)
    {
        auto geometry = feature["geometry"];
        json coords = geometry["coordinates"];
        //printf("coords size %d\n", coords.size());
        for(auto coord : coords)
        {
            if(coords.size() != 1)
            {
                double x = coord.at(0);
                double y = coord.at(1);
                double z = coord.at(2);    
                printf("%0.16f %0.16f %0.16f\n", x, y, z);          
            }
            else
            {
                auto coord_ = coords[0];
                for(auto coord__ : coord_)
                {
                    double x = coord__.at(0);
                    double y = coord__.at(1);
                    double z = coord__.at(2);                                        
                    printf("%0.16f %0.16f %0.16f\n", x, y, z);          
                }
            }
        }
    }

    return 1;
}
