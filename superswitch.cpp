#include <iostream>
#include <map>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

void loadColorToIntMap(map<string,unsigned int> &colorToInt);
void loadIntToColorMap(map<unsigned int, string> &intToColor);
void display(unsigned int x, map<unsigned int, string> intToColor );

int test()
{
    unsigned int sets[26];
    map<unsigned int, string> intToColor;
    map<string, unsigned int> colorToInt;
    loadColorToIntMap(colorToInt);
    loadIntToColorMap(intToColor);
    srand(time(nullptr));

    for(int i = 0; i < 25; ++i)
        sets[i] = rand()%(17);

    sets[25] = colorToInt["WHITE"] | colorToInt["PURPLE"] | colorToInt["BLACK"];

//    for(int i = 0; i < 26; ++i)
//    {
//        cout<<"set["<<i<<"] = "<<sets[i]<<" = ";
//        display(sets[i],intToColor);
//    }

//    sets[25] = sets[22] | sets[19]; //Union
//    display(sets[25],intToColor);
//    sets[25] = sets[22] & sets[19]; //Intersection
//    display(sets[25],intToColor);

    return 0;
}


void display(unsigned int x, map<unsigned int, string> intToColor )
{
    unsigned int mask = 1;
    cout<<"{";
    while(mask <= 32768)
    {
        if(intToColor.count(mask & x))
            cout<< intToColor[mask & x] << " ";
        mask <<= 1;
    }
    cout<<"}"<<endl;

}

void loadIntToColorMap(map<unsigned int, string> &intToColor)
{
    intToColor[1] = "WHITE";
    intToColor[2] = "GOLD";
    intToColor[4] = "GRAY";
    intToColor[8] = "RED";
    intToColor[16] = "GREEN";
    intToColor[32] = "BLUE";
    intToColor[64] = "ORANGE";
    intToColor[128] = "PURPLE";
    intToColor[256] = "YELLOW";
    intToColor[512] = "VIOLET";
    intToColor[1024] = "MAGENTA";
    intToColor[2048] = "CYAN";
    intToColor[4096] = "RUST";
    intToColor[8192] = "NAVY";
    intToColor[16384] = "BURGUNDY";
    intToColor[32768] = "BLACK";
}

void loadColorToIntMap(map<string, unsigned int> &colorToInt)
{
    colorToInt["WHITE"] = 1;
    colorToInt["GOLD"] = 2;
    colorToInt["GRAY"] = 4;
    colorToInt["RED"] = 8;
    colorToInt["GREEN"] = 16;
    colorToInt["BLUE"] = 32;
    colorToInt["ORANGE"] = 64;
    colorToInt["PURPLE"] = 128;
    colorToInt["YELLOW"] = 256;
    colorToInt["VIOLET"] = 512;
    colorToInt["MAGENTA"] = 1024;
    colorToInt["CYAN"] = 2048;
    colorToInt["RUST"] = 4096;
    colorToInt["NAVY"] = 8192;
    colorToInt["BURGUNDY"] = 16384;
    colorToInt["BLACK"] = 32768;
}
