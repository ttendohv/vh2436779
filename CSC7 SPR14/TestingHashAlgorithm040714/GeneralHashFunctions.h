/* Victoria Hodnett
 * Hashing Function 03/26/14
 */

/*
 **************************************************************************
 *                                                                        *
 *          General Purpose Hash Function Algorithms Library              *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the most current *
 * version of the Common Public License.                                  *
 * http://www.opensource.org/licenses/cpl1.0.php                          *
 *                                                                        *
 **************************************************************************
*/


#ifndef INCLUDE_GENERALHASHFUNCTION_CPP_H
#define INCLUDE_GENERALHASHFUNCTION_CPP_H


#include <string>
using namespace std;


typedef unsigned int (*HashFunction)(const string&);


unsigned int RSHash  (const string& str);
unsigned int JSHash  (const string& str);
unsigned int PJWHash (const string& str);
unsigned int ELFHash (const string& str);
unsigned int BKDRHash(const string& str);
unsigned int SDBMHash(const string& str);
unsigned int DJBHash (const string& str);
unsigned int DEKHash (const string& str);
unsigned int BPHash  (const string& str);
unsigned int FNVHash (const string& str);
unsigned int APHash  (const string& str);


#endif
