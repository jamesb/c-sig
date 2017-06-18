/*
 * This program basically decodes the properly encoded data string into the
 * following seven characters: (space), (newline), "/", "(", "-", "_", ")"
 * In this case, the output will read as follows:
 *
 *    /_ _  _  _   /_)_ _    _ _
 * (_/(///)(-_)   /_)(-/ /)_) (-/)
 *
 *
 */

/*
 * z is our encoded data string.  The data is encoded as follows:
 *
 * 1. Each of the seven legal characters is given a code:
 *    "("   [left paren] ==      0
 *    ")"   [right paren ==      1
 *    " "   [space] ==           2
 *    "/"   [forward slash] ==   3
 *    "_"   [underscore] ==      4
 *    "-"   [hyphen] ==          5
 *    "\n"  [new line] ==        6
 *
 * 2. Those codes are grouped in pairs.  For example, if the digits from step
 *    one were 0550 then the pairs would be 05 50.  These pairs will be
 *    treated as base seven numbers.
 *
 * 3. Convert the base 7 numbers into decimal.  For example, 05 would be
 *    converted to 5, 50 to 35, 10 to 7, etc.
 *
 * 4. To each of these numbers, we add 60.  (This makes them fit mainly into
 *    the easily-typeable portion of the ASCII character set.)
 *
 * 5. Replace each of these numbers with their ASCII character component.
 *    Note: if 92 (which translates to a backslash) is in this numeric set,
 *    be sure to replace it with two backslashes because C recognizes
 *    the backslash as an escape character.
 */
char*z="lLMZZNLZLUGNLLZZP@QTRAYLMYASRYJbIl";


/*
 * Here's our main function.  Notice that it declares x and y
 */
main(x,y) {

/*
 * Everything works by looping through each character in the data string
 * (z) twice.  We do this to decode each base seven pair into its two
 * components.  Notice that we place each character into y, and we
 * also do the subtraction of sixty right here in the loop.  The loop
 * will continue until the end of the string is reached (that's where
 * y will equal negative sixty: the null character minus sixty.)
 */
   for(x=0;(y=z[x/2]-60)>-60;x++){
/*
 * This next conditional basically determines whether we are decoding the
 * first or second component of the pair and sets y to the correct value.
 */
      y=x%2?y%7:y/7;

/*
 * This next part decodes y into the appropriate printable character as
 * listed in step 1 of the data decoding section above so that it can
 * be printed.
 */
      y=y<2||y==5?y+40:y>1&&y<4?15*y+2:y==4?y+91:y+4;
      putchar(y);
   }
}

