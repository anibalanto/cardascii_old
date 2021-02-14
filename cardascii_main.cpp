/*
    OneLoneCoder.com - Command Line Tetris
    "Put Your Money Where Your Mouth Is" - @Javidx9
    
    License
    ~~~~~~~
    Copyright (C) 2018  Javidx9
    This program comes with ABSOLUTELY NO WARRANTY.
    This is free software, and you are welcome to redistribute it
    under certain conditions; See license for details. 
    Original works located at:
    https://www.github.com/onelonecoder
    https://www.onelonecoder.com
    https://www.youtube.com/javidx9

    GNU GPLv3
    https://github.com/OneLoneCoder/videos/blob/master/LICENSE

    From Javidx9 :)
    ~~~~~~~~~~~~~~~
    Hello! Ultimately I don't care what you use this for. It's intended to be 
    educational, and perhaps to the oddly minded - a little bit of fun. 
    Please hack this, change it and use it in any way you see fit. You acknowledge 
    that I am not responsible for anything bad that happens as a result of 
    your actions. However this code is protected by GNU GPLv3, see the license in the
    github repo. This means you must attribute me if you use it. You can view this
    license here: https://github.com/OneLoneCoder/videos/blob/master/LICENSE
    Cheers!
    
    Background
    ~~~~~~~~~~
    I made a video "8-Bits of advice for new programmers" (https://youtu.be/vVRCJ52g5m4)
    and suggested that building a tetris clone instead of Dark Sould IV might be a better 
    approach to learning to code. Tetris is nice as it makes you think about algorithms. 
    
    Controls are Arrow keys Left, Right & Down. Use Z to rotate the piece. 
    You score 25pts per tetronimo, and 2^(number of lines)*100 when you get lines.
    
    Future Modifications
    ~~~~~~~~~~~~~~~~~~~~
    1) Show next block and line counter
    
    Author
    ~~~~~~
    Twitter: @javidx9
    Blog: www.onelonecoder.com
    
    Video:
    ~~~~~~
    https://youtu.be/8OK8_tHeCIA
    
    Last Updated: 30/03/2017
*/

#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

#include "rang.hpp"

using namespace std;
using namespace rang;

#include <stdio.h>

const int nScreenWidth = 40;            // Console Screen Size X (columns)
const int nScreenHeight = 40;            // Console Screen Size Y (rows)

int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr;

struct string_line {
    int inic;
    wstring line;
    
};

using ascii_figure = vector<string_line>;

ascii_figure cardascii[50];

void load_cards();
void compose(wchar_t scene[nScreenHeight][nScreenWidth], ascii_figure figure, int x, int y);
void reset(wchar_t screen[nScreenHeight][nScreenWidth]);

int main()
{
    // Create Screen Buffer
    wchar_t screen[nScreenHeight][nScreenWidth];
    reset(screen);

    load_cards();

    int s = 0;
    while(true) {
        compose(screen, cardascii[2], 2, 2);
        compose(screen, cardascii[3], 11, 1);
        compose(screen, cardascii[0], 19, 3+s++);


        for (int i = 0; i < nScreenHeight; i++) {
            for(int j = 0; j < nScreenWidth; j++)
                wcout << screen[i][j];
            wcout << endl;
        }

        getchar();
        reset(screen);
    }
    
    return 0;
}

void reset(wchar_t screen[nScreenHeight][nScreenWidth]) {
    for (int i = 0; i < nScreenWidth; i++)
        for (int j = 0; j < nScreenHeight; j++)
            screen[i][j] = L' ';
}

void compose(wchar_t screen[nScreenHeight][nScreenWidth], ascii_figure figure, int x, int y) {
    int row = y;
    for(auto sline : figure) {
        if(row < nScreenHeight) {
            int lcolumn= x + sline.inic + sline.line.size();
            for(int j = 0; j+x < min(nScreenWidth, lcolumn); j++) {
                screen[row][j+x] = sline.line.at(j);
            }
            row++;
        } else {
            break;
        }
    }
}


#define CARD(str)                           \
do {                          \
    string_line sl;\
    sl.inic = 0;\
    sl.line = str;                          \
    cardascii[ncard].push_back(sl);   \
} while (0)

#define END_CARD()                      \
do {                                    \
    ncard++;                            \
} while (0)

inline void load_cards() {
    
    uint ncard = 0; 

    CARD(LR"(┌────────────┐)");
    CARD(LR"(│J    o   o  │)");
    CARD(LR"(│O  o |\  |\ │)");
    CARD(LR"(│K  |\/_|/_| │)");
    CARD(LR"(│E |;  x  o| │)");
    CARD(LR"(│R  \    _|  │)");
    CARD(LR"(│   | `-/    │)");
    CARD(LR"(│            │)");
    CARD(LR"(└────────────┘)");END_CARD();

    CARD(LR"(┌────────────┐)");
    CARD(LR"(│J    o   o  │)");
    CARD(LR"(│O  o |\  |\ │)");
    CARD(LR"(│K  |\/_|/_| │)");
    CARD(LR"(│E |;  x  o| │)");
    CARD(LR"(│R  \    _|  │)");
    CARD(LR"(│   | `-/    │)");
    CARD(LR"(│            │)");
    CARD(LR"(└────────────┘)");END_CARD();

    CARD(LR"(┌────────────┐)");
    CARD(LR"(│12  /┼^^^^\ │)");
    CARD(LR"(│|\ (o_.o   )│)");
    CARD(LR"(│ \\ \     / │)");
    CARD(LR"(│ _\\_-&---\ │)");
    CARD(LR"(│   B .@.   \│)");
    CARD(LR"(│  /  |@|    │)");
    CARD(LR"(│ /   |@|  12│)");
    CARD(LR"(└────────────┘)");END_CARD();

    CARD(LR"(┌────────────┐)");
    CARD(LR"(│11    ┌─@──┐│)");
    CARD(LR"(│|\    (o_ o)│)");
    CARD(LR"(│ \\   /    \│)");
    CARD(LR"(│ _\\_D__D   │)");//HORSE(R"(┌     D__D   ┐)");
    CARD(LR"(│   B(o  o)__│)");//HORSE(R"(┌    (o  o)__┐)");
    CARD(LR"(│    /  /    │)");//HORSE(R"(┌    /  /    ┐)");
    CARD(LR"(│   (..) \ 11│)");//HORSE(R"(┌   (..) \   ┐)");
    CARD(LR"(└────────────┘)");END_CARD();

    CARD(LR"(┌────────────┐)");
    CARD(LR"(│10   ┌@───┐ │)");
    CARD(LR"(│     │____│ │)");
    CARD(LR"(│ |\  (o_ o) │)");
    CARD(LR"(│  \\ /    \ │)");
    CARD(LR"(│  _\\_    / │)");
    CARD(LR"(│    B \  /B │)");
    CARD(LR"(│       || 10│)");
    CARD(LR"(└────────────┘)");END_CARD();

    CARD(LR"(┌────────────┐)");
    CARD(LR"(│9           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│   |\       │)");
    CARD(LR"(│    \\      │)");
    CARD(LR"(│    _\\_    │)");
    CARD(LR"(│      \     │)");
    CARD(LR"(│           9│)");
    CARD(LR"(└────────────┘)");END_CARD();

    CARD(LR"(┌────────────┐)");
    CARD(LR"(│8           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│   |\       │)");
    CARD(LR"(│    \\      │)");
    CARD(LR"(│    _\\_    │)");
    CARD(LR"(│      \     │)");
    CARD(LR"(│           8│)");
    CARD(LR"(└────────────┘)");END_CARD();

    CARD(LR"(┌────────────┐)");
    CARD(LR"(│7           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│   |\       │)");
    CARD(LR"(│    \\      │)");
    CARD(LR"(│    _\\_    │)");
    CARD(LR"(│      \     │)");
    CARD(LR"(│           7│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│6           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│   |\       │)");
    CARD(LR"(│    \\      │)");
    CARD(LR"(│    _\\_    │)");
    CARD(LR"(│      \     │)");
    CARD(LR"(│           6│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│5           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│   |\       │)");
    CARD(LR"(│    \\      │)");
    CARD(LR"(│    _\\_    │)");
    CARD(LR"(│      \     │)");
    CARD(LR"(│           5│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│4           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│   |\       │)");
    CARD(LR"(│    \\      │)");
    CARD(LR"(│    _\\_    │)");
    CARD(LR"(│      \     │)");
    CARD(LR"(│           4│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│3           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│   |\       │)");
    CARD(LR"(│    \\      │)");
    CARD(LR"(│    _\\_    │)");
    CARD(LR"(│      \     │)");
    CARD(LR"(│           3│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│2           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│   |\       │)");
    CARD(LR"(│    \\      │)");
    CARD(LR"(│    _\\_    │)");
    CARD(LR"(│      \     │)");
    CARD(LR"(│           2│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│1           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│   |\       │)");
    CARD(LR"(│    \\      │)");
    CARD(LR"(│    _\\_    │)");
    CARD(LR"(│      \     │)");
    CARD(LR"(│           1│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│12  /┼^^^^\ │)");
    CARD(LR"(│.-.(o_.o   )│)");
    CARD(LR"(│(  )\     / │)");
    CARD(LR"(│ ( )/-&---\ │)");
    CARD(LR"(│  () .@.   \│)");
    CARD(LR"(│  /  |@|    │)");
    CARD(LR"(│ /   |@|  12│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│11    ┌─@──┐│)");
    CARD(LR"(│.-.   (o_ o)│)");
    CARD(LR"(│(  )  /    \│)");
    CARD(LR"(│ ( ) D__D   │)");
    CARD(LR"(│  ()(o  o)__│)");
    CARD(LR"(│    /  /    │)");
    CARD(LR"(│   (..) \ 11│)");
    CARD(LR"(└────────────┘)");END_CARD();

    CARD(LR"(┌────────────┐)");
    CARD(LR"(│10   ┌@───┐ │)");
    CARD(LR"(│.-.  │____│ │)");
    CARD(LR"(│(  ) (o_ o) │)");
    CARD(LR"(│ ( ) /    \ │)");
    CARD(LR"(│  ()/\    / │)");
    CARD(LR"(│      \  /B │)");
    CARD(LR"(│       || 10│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│9           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│    (  )    │)");
    CARD(LR"(│     ( )    │)");
    CARD(LR"(│      ()    │)");
    CARD(LR"(│           9│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│8           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│    (  )    │)");
    CARD(LR"(│     ( )    │)");
    CARD(LR"(│      ()    │)");
    CARD(LR"(│           8│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│7           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│    (  )    │)");
    CARD(LR"(│     ( )    │)");
    CARD(LR"(│      ()    │)");
    CARD(LR"(│           7│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│6           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│    (  )    │)");
    CARD(LR"(│     ( )    │)");
    CARD(LR"(│      ()    │)");
    CARD(LR"(│           6│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│5           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│    (  )    │)");
    CARD(LR"(│     ( )    │)");
    CARD(LR"(│      ()    │)");
    CARD(LR"(│           5│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│4           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│    (  )    │)");
    CARD(LR"(│     ( )    │)");
    CARD(LR"(│      ()    │)");
    CARD(LR"(│           4│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│3           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│    (  )    │)");
    CARD(LR"(│     ( )    │)");
    CARD(LR"(│      ()    │)");
    CARD(LR"(│           3│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│2           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│    (  )    │)");
    CARD(LR"(│     ( )    │)");
    CARD(LR"(│      ()    │)");
    CARD(LR"(│           2│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│1           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│    (  )    │)");
    CARD(LR"(│     ( )    │)");
    CARD(LR"(│      ()    │)");
    CARD(LR"(│           1│)");
    CARD(LR"(└────────────┘)");END_CARD();

    CARD(LR"(┌────────────┐)");
    CARD(LR"(│12  /┼^^^^\ │)");
    CARD(LR"(│   (o_.o   )│)");
    CARD(LR"(│ .-.\     / │)");
    CARD(LR"(│( O )-&---\ │)");
    CARD(LR"(│B`-` .@.   \│)");
    CARD(LR"(│  /  |@|    │)");
    CARD(LR"(│ /   |@|  12│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│11    ┌─@──┐│)");
    CARD(LR"(│ .-.  (o_ o)│)");
    CARD(LR"(│( O ) /    \│)");
    CARD(LR"(│ `-` D__D   │)");
    CARD(LR"(│    (o  o)__│)");
    CARD(LR"(│    /  /    │)");
    CARD(LR"(│   (..) \ 11│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│10   ┌@───┐ │)");
    CARD(LR"(│     │____│ │)");
    CARD(LR"(│ .-. (o_ o) │)");
    CARD(LR"(│( O )/    \ │)");
    CARD(LR"(│ `-` \    / │)");
    CARD(LR"(│      \  /B │)");
    CARD(LR"(│       || 10│)");
    CARD(LR"(└────────────┘)");END_CARD();

    CARD(LR"(┌────────────┐)");
    CARD(LR"(│9           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│   ( O )    │)");
    CARD(LR"(│    `-`     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           9│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│8           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│   ( O )    │)");
    CARD(LR"(│    `-`     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           8│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│7           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│   ( O )    │)");
    CARD(LR"(│    `-`     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           7│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│6           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│   ( O )    │)");
    CARD(LR"(│    `-`     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           6│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│5           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│   ( O )    │)");
    CARD(LR"(│    `-`     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           5│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│4           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│   ( O )    │)");
    CARD(LR"(│    `-`     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           4│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│3           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│   ( O )    │)");
    CARD(LR"(│    `-`     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           3│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│2           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│   ( O )    │)");
    CARD(LR"(│    `-`     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           2│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│1           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    .-.     │)");
    CARD(LR"(│   ( O )    │)");
    CARD(LR"(│    `-`     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           1│)");
    CARD(LR"(└────────────┘)");END_CARD();

    CARD(LR"(┌────────────┐)");
    CARD(LR"(│12  /┼^^^^\ │)");
    CARD(LR"(│   (o_.o   )│)");
    CARD(LR"(│ ___\     / │)");
    CARD(LR"(│(___)-&---\ │)");
    CARD(LR"(│B\_/ .@.   \│)");
    CARD(LR"(│  /  |@|    │)");
    CARD(LR"(│ /   |@|  12│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│11    ┌─@──┐│)");
    CARD(LR"(│ ___  (o_ o)│)");
    CARD(LR"(│(___) /    \│)");
    CARD(LR"(│ \_/ D__D   │)");
    CARD(LR"(│    (o  o)__│)");
    CARD(LR"(│    /  /    │)");
    CARD(LR"(│   (..) \ 11│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│10   ┌@───┐ │)");
    CARD(LR"(│     │____│ │)");
    CARD(LR"(│ ___ (o_ o) │)");
    CARD(LR"(│(___)/    \ │)");
    CARD(LR"(│ \_/ \    / │)");
    CARD(LR"(│      \  /B │)");
    CARD(LR"(│       || 10│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│9           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    ___     │)");
    CARD(LR"(│   (___)    │)");
    CARD(LR"(│    \_/     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           9│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│8           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    ___     │)");
    CARD(LR"(│   (___)    │)");
    CARD(LR"(│    \_/     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           8│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│7           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    ___     │)");
    CARD(LR"(│   (___)    │)");
    CARD(LR"(│    \_/     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           7│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│6           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    ___     │)");
    CARD(LR"(│   (___)    │)");
    CARD(LR"(│    \_/     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           6│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│5           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    ___     │)");
    CARD(LR"(│   (___)    │)");
    CARD(LR"(│    \_/     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           5│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│4           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    ___     │)");
    CARD(LR"(│   (___)    │)");
    CARD(LR"(│    \_/     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           4│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│3           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    ___     │)");
    CARD(LR"(│   (___)    │)");
    CARD(LR"(│    \_/     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           3│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│2           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    ___     │)");
    CARD(LR"(│   (___)    │)");
    CARD(LR"(│    \_/     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           2│)");
    CARD(LR"(└────────────┘)");END_CARD();
    
    CARD(LR"(┌────────────┐)");
    CARD(LR"(│1           │)");
    CARD(LR"(│            │)");
    CARD(LR"(│    ___     │)");
    CARD(LR"(│   (___)    │)");
    CARD(LR"(│    \_/     │)");
    CARD(LR"(│            │)");
    CARD(LR"(│           1│)");
    CARD(LR"(└────────────┘)");END_CARD();

}
