#ifndef _COLORS_HPP_
#define _COLORS_HPP_

// ANSI Colour Escape Codes.
#define RST  "\x1B[0m"      // reset colour

// Bold Bright Colour Codes
#define KRED  "\x1B[1m\x1B[91m"
#define KGRN  "\x1B[1m\x1B[92m"
#define KYEL  "\x1B[1m\x1B[93m"
#define KBLU  "\x1B[1m\x1B[94m"
#define KMAG  "\x1B[1m\x1B[95m"
#define KCYN  "\x1B[1m\x1B[96m"
#define KWHT  "\x1B[1m\x1B[97m"

// type: cout << FRED("something") << endl;
#define BRED(x) KRED x RST  // bright red
#define BGRN(x) KGRN x RST  // bright green
#define BYEL(x) KYEL x RST  // bright yellow
#define BBLU(x) KBLU x RST  // bright blue
#define BMAG(x) KMAG x RST  // bright magenta
#define BCYN(x) KCYN x RST  // bright cyan
#define BWHT(x) KWHT x RST  // white

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#define Bold "\x1B[1m"      // start bold

#endif
