#include <iostream>
#include <cstdio>
#include <string>
#include <thread>


using namespace std;

const int numRows = 50;
const int numColumns = 170;
int delayTimeMillis = 1; 
class FrameBuffer
{
public:
    int rows;
    int columns;
    string buffer;
    FrameBuffer(int r, int c)
    {
        this->rows = r;
        this->columns = c;
        this->buffer = "";
        this->initialize();
    }

    void draw()
    {
        // clear the console
        std::system("cls");
        // initially set the size of the screen buffer (right now its 0)
        for (int r = 0; r < this->rows; r++)
        {
            for (int c = 0; c < this->columns; c++)
            {
                std::cout << this->buffer[(r * numColumns) + c]; // std::to_string(r+c)<<",";
                this_thread::sleep_for(std::chrono::milliseconds(delayTimeMillis)); 
            }
            // when we make a new row, add a \n
            std::cout << "\n";
        }
    }
    void initialize()
    {
        // wipe the screen.
        this->buffer = "";
        // initially set the size of the screen buffer (right now its 0)
        for (int r = 0; r < this->rows; r++)
        {
            for (int c = 0; c < this->columns; c++)
            {
                this->buffer += ' ';
            }
        }
    }

    // boxwidth determines how many chars wide the
    // text will be drawn.
    void drawText(int x, int y, string text, int width)
    {
        int rows = (text.length() / width) + 1; // add an extra row just in case of rounding sillyness =]
        for (int r = 0; r < rows; r++)
        {
            // In this nested part, we're actually traversing back and forth
            // across a few spots that are the width given by the user
            // we reset and go down an entire row of pixels when we go past the width
            // and start again, from left to right until we get to the width of the text box again.
            for (int c = 0; c < width; c++)
            {
                // essentially stop drawing text if we decide that we're past the length of the
                // text given by the function call.
                // If we don't do this, the extra row that we added so that the text doesn't get
                // clipped, will alow us to read past the text we were given.
                if (((r * width) + c) < text.length())
                {
                    this->buffer[((y + r) * numColumns) + c + x] = text[(r * width) + c];
                }
            }
            // Old way of getting text into buffer: this->buffer[x + (numColumns* y) + i] = text[i];
        }
    }
};

int main()
{
    //std::cout<<"The delay is optional. It's added for aesthetics."; 
    //this_thread::sleep_for(std::chrono::milliseconds(5000)); 
    std::system("clear"); 
    FrameBuffer myBuffer(numRows, numColumns);
    std::cout << myBuffer.rows << " rows, " << myBuffer.columns << " columns\n";
    // int numTimes = 13;
    // for(int i = 0; i < numTimes; i++) {
    //     myBuffer.draw();
    //     std::cout<<"Draw times: " << std::to_string(i) << "\n";
    //     this_thread::sleep_for(std::chrono::seconds(1));
    // }
    string message("Hello, world! this message is wrapped by a constraining number.");
    //myBuffer.drawText(5, 0, message, 10);
    string stuff = "This message isn't wrapped much.";
    //myBuffer.drawText(25, 10, stuff, 20);
    string message2 = "This message is tightly wrapped.";
    //myBuffer.drawText(20, 15, message2, 8);
    string message3 = "Narrowing conversion happens when you divide two numbers and store the answer in a number that cannot hold the answer to full precision. Even though we divide 2 floats 1.000000 and 2.000000 , the issue is that we'ere storing the result in a int";
    //myBuffer.drawText(40, 0, message3, 20);
    string message4 = "The heavens declare the glory of God, and the sky above proclaims his handiwork. 2 Day to day pours out speech, and night to night reveals knowledge. 3 There is no speech, nor are there words, whose voice is not heard. 4 Their voice goes out through all the earth, and their words to the end of the world. In them he has set a tent for the sun, 5 which comes out like a bridegroom leaving his chamber, and, like a strong man, runs its course with joy. 6 Its rising is from the end of the heavens, and its circuit to the end of them, and there is nothing hidden from its heat. 7 The law of the LORD is perfect, reviving the soul; the testimony of the LORD is sure, making wise the simple; 8 the precepts of the LORD are right, rejoicing the heart; the commandment of the LORD is pure, enlightening the eyes; 9 the fear of the LORD is clean, enduring forever; the rules of the LORD are true, and righteous altogether. 10 More to be desired are they than gold, even much fine gold; sweeter also than honey and drippings of the honeycomb. 11 Moreover, by them is your servant warned; in keeping them there is great reward. The Holy Bible: English Standard Version (Wheaton, IL: Crossway Bibles, 2016), Ps 19:1-11.";
    //myBuffer.drawText(10, 20, message4, 60);
    //myBuffer.drawText(80,0,message4,45); 
    myBuffer.drawText(30,0,message4,30);
    myBuffer.draw();
    return 0;
}

/*

// Block Elements on Wiki!
// https://en.wikipedia.org/wiki/Block_Elements
// ░	Light shade
// ▒	Medium shade
// ▓    Dark Shade

Code	Result	Description
U+2580	▀	Upper half block
U+2581	▁	Lower one eighth block
U+2582	▂	Lower one quarter block
U+2583	▃	Lower three eighths block
U+2584	▄	Lower half block
U+2585	▅	Lower five eighths block
U+2586	▆	Lower three quarters block
U+2587	▇	Lower seven eighths block
U+2588	█	Full block
U+2589	▉	Left seven eighths block
U+258A	▊	Left three quarters block
U+258B	▋	Left five eighths block
U+258C	▌	Left half block
U+258D	▍	Left three eighths block
U+258E	▎	Left one quarter block
U+258F	▏	Left one eighth block
U+2590	▐	Right half block
U+2591	░	Light shade
U+2592	▒	Medium shade
U+2593	▓	Dark shade
U+2594	▔	Upper one eighth block
U+2595	▕	Right one eighth block
U+2596	▖	Quadrant lower left
U+2597	▗	Quadrant lower right
U+2598	▘	Quadrant upper left
U+2599	▙	Quadrant upper left and lower left and lower right
U+259A	▚	Quadrant upper left and lower right
U+259B	▛	Quadrant upper left and upper right and lower left
U+259C	▜	Quadrant upper left and upper right and lower right
U+259D	▝	Quadrant upper right
U+259E	▞	Quadrant upper right and lower left
U+259F	▟	Quadrant upper right and lower left and lower right
*/

/*
▒▒▒▒▒▒▒▒▒▒▒
▒         ▒
▒         ▒
▒         ▒
▒         ▒
▒         ▒
▒▒▒▒▒▒▒▒▒▒▒

You can format your console to use specific colors!
    //std::cout << "\033[34m"; // Blue foreground
    //std::cout << "blue text";
    //std::cout << "\033[31m"; // Red foreground
    //std::cout << "red text";
https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
Value	Description	Behavior
0	Default	Returns all attributes to the default state prior to modification
1	Bold/Bright	Applies brightness/intensity flag to foreground color
22	No bold/bright	Removes brightness/intensity flag from foreground color
4	Underline	Adds underline
24	No underline	Removes underline
7	Negative	Swaps foreground and background colors
27	Positive (No negative)	Returns foreground/background to normal
30	Foreground Black	Applies non-bold/bright black to foreground
31	Foreground Red	Applies non-bold/bright red to foreground
32	Foreground Green	Applies non-bold/bright green to foreground
33	Foreground Yellow	Applies non-bold/bright yellow to foreground
34	Foreground Blue	Applies non-bold/bright blue to foreground
35	Foreground Magenta	Applies non-bold/bright magenta to foreground
36	Foreground Cyan	Applies non-bold/bright cyan to foreground
37	Foreground White	Applies non-bold/bright white to foreground
38	Foreground Extended	Applies extended color value to the foreground (see details below)
39	Foreground Default	Applies only the foreground portion of the defaults (see 0)
40	Background Black	Applies non-bold/bright black to background
41	Background Red	Applies non-bold/bright red to background
42	Background Green	Applies non-bold/bright green to background
43	Background Yellow	Applies non-bold/bright yellow to background
44	Background Blue	Applies non-bold/bright blue to background
45	Background Magenta	Applies non-bold/bright magenta to background
46	Background Cyan	Applies non-bold/bright cyan to background
47	Background White	Applies non-bold/bright white to background
48	Background Extended	Applies extended color value to the background (see details below)
49	Background Default	Applies only the background portion of the defaults (see 0)
90	Bright Foreground Black	Applies bold/bright black to foreground
91	Bright Foreground Red	Applies bold/bright red to foreground
92	Bright Foreground Green	Applies bold/bright green to foreground
93	Bright Foreground Yellow	Applies bold/bright yellow to foreground
94	Bright Foreground Blue	Applies bold/bright blue to foreground
95	Bright Foreground Magenta	Applies bold/bright magenta to foreground
96	Bright Foreground Cyan	Applies bold/bright cyan to foreground
97	Bright Foreground White	Applies bold/bright white to foreground
100	Bright Background Black	Applies bold/bright black to background
101	Bright Background Red	Applies bold/bright red to background
102	Bright Background Green	Applies bold/bright green to background
103	Bright Background Yellow	Applies bold/bright yellow to background
104	Bright Background Blue	Applies bold/bright blue to background
105	Bright Background Magenta	Applies bold/bright magenta to background
106	Bright Background Cyan	Applies bold/bright cyan to background
107	Bright Background White	Applies bold/bright white to background

Extended Colors
Some virtual terminal emulators support a palette of colors greater than the 16 colors provided by the Windows Console. For these extended colors, the Windows Console will choose the nearest appropriate color from the existing 16 color table for display. Unlike typical SGR values above, the extended values will consume additional parameters after the initial indicator according to the table below.

SGR Subsequence	Description
38 ; 2 ; <r> ; <g> ; <b>	Set foreground color to RGB value specified in <r>, <g>, <b> parameters*
48 ; 2 ; <r> ; <g> ; <b>	Set background color to RGB value specified in <r>, <g>, <b> parameters*
38 ; 5 ; <s>	Set foreground color to <s> index in 88 or 256 color table*
48 ; 5 ; <s>	Set background color to <s> index in 88 or 256 color table*
*The 88 and 256 color palettes maintained internally for comparison are based from the xterm terminal emulator. The comparison/rounding tables cannot be modified at this time.





Window Title
The following commands allows the application to set the title of the console window to the given <string> parameter. The string must be less than 255 characters to be accepted. This is equivalent to calling SetConsoleTitle with the given string.

Note that these sequences are OSC “Operating system command” sequences, and not a CSI like many of the other sequences listed, and as such starts with “\x1b]”, not “\x1b[”. As OSC sequences, they are ended with a String Terminator represented as <ST> and transmitted with ESC \ (0x1B 0x5C). BEL (0x7) may be used instead as the terminator, but the longer form is preferred.

Sequence	Description	Behavior
ESC ] 0 ; <string> <ST>	Set Window Title	Sets the console window’s title to <string>.
ESC ] 2 ; <string> <ST>	Set Window Title	Sets the console window’s title to <string>.


*/
