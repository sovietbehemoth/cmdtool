#define upper_macro \
    switch (string[i]) { \
        case 'a': retval[pos] = 'A'; break; \
        case 'b': retval[pos] = 'B'; break; \
        case 'c': retval[pos] = 'C'; break; \
        case 'd': retval[pos] = 'D'; break; \
        case 'e': retval[pos] = 'E'; break; \
        case 'f': retval[pos] = 'F'; break; \
        case 'g': retval[pos] = 'G'; break; \
        case 'h': retval[pos] = 'H'; break; \
        case 'i': retval[pos] = 'I'; break; \
        case 'j': retval[pos] = 'J'; break; \
        case 'k': retval[pos] = 'K'; break; \
        case 'l': retval[pos] = 'L'; break; \
        case 'm': retval[pos] = 'M'; break; \
        case 'n': retval[pos] = 'N'; break; \
        case 'o': retval[pos] = 'O'; break; \
        case 'p': retval[pos] = 'P'; break; \
        case 'q': retval[pos] = 'Q'; break; \
        case 'r': retval[pos] = 'R'; break; \
        case 's': retval[pos] = 'S'; break; \
        case 't': retval[pos] = 'T'; break; \
        case 'u': retval[pos] = 'U'; break; \
        case 'v': retval[pos] = 'V'; break; \
        case 'w': retval[pos] = 'W'; break; \
        case 'x': retval[pos] = 'X'; break; \
        case 'y': retval[pos] = 'Y'; break; \
        case 'z': retval[pos] = 'Z'; break; \
        default: { \
            retval[pos] = string[i]; \
        } \
    }   \


#define lower_macro \
    switch (string[i]) {    \
        case 'A': retval[pos] = 'a'; break; \
        case 'B': retval[pos] = 'b'; break; \
        case 'C': retval[pos] = 'c'; break; \
        case 'D': retval[pos] = 'd'; break; \
        case 'E': retval[pos] = 'e'; break; \
        case 'F': retval[pos] = 'f'; break; \
        case 'G': retval[pos] = 'g'; break; \
        case 'H': retval[pos] = 'h'; break; \
        case 'I': retval[pos] = 'i'; break; \
        case 'J': retval[pos] = 'j'; break; \
        case 'K': retval[pos] = 'k'; break; \
        case 'L': retval[pos] = 'l'; break; \
        case 'M': retval[pos] = 'm'; break; \
        case 'N': retval[pos] = 'n'; break; \
        case 'O': retval[pos] = 'o'; break; \
        case 'P': retval[pos] = 'p'; break; \
        case 'Q': retval[pos] = 'q'; break; \
        case 'R': retval[pos] = 'r'; break; \
        case 'S': retval[pos] = 's'; break; \
        case 'T': retval[pos] = 't'; break; \
        case 'U': retval[pos] = 'u'; break; \
        case 'V': retval[pos] = 'v'; break; \
        case 'W': retval[pos] = 'w'; break; \
        case 'X': retval[pos] = 'x'; break; \
        case 'Y': retval[pos] = 'y'; break; \
        case 'Z': retval[pos] = 'z'; break; \
        default: {  \
            retval[pos] = string[i];    \
        }   \
    }   \

//THWART COMPILER ERROR