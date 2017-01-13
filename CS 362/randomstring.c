/********************************
* Name: Grant Nakashima
* Due Date: 7/11/16
* Assignment: Quiz 2
* Class: 362
(********************************/

Function inputChar() :
	The function returns a random character that is based on the ASCII value.The ASCII table is used to find the
	the range of values which are from 32 to 125. 32 returns a space ' ' while 125 returns a '}'. Other characters
	that are required to appear will show up under the range used. The function gets a number at random before adding 
	32 to get the correct range. It will eventually meet the if statement conditions to get to state 9. 


Function inputString():
	The function returns a char string that is 6 characters long. The first loop of the function will build a string randomly and
	have a null terminator added onto the end of the string. Once the string has been returned, it will be used and tested in the 
	last if statement if state = 9. The second loop of the function will build a string like the first loop except it provides a
	much greater chance of creating a string that returns 'reset'. The loop is provided with a char string that is already 'reset'. It
	will make a copy of the string by using random indexes. The loop may or may not return 'reset'. This was implemented to speed up the
	chance of 'reset' from appearing. In my test below, it was able to print 'reset' after 1226 iterations. If the first loop was only used,
	the chances of it appearing is 1 out of 26 ^ 5 (11, 881, 376). 

Analysis:
	After looking at the code for testme.c, it appears the goal of the testing is to see if the output error message will be error
	if we use random values. For the message to get printed, it will need to perform the 9th state. The 9th state is performed when 
	the previous calls to inputChar() return '[' '(' '{' '' 'a' 'x' '}' ')' ']' in that order for its respective state. The last condition that must be met in order to 
	print 'error' is the last call to inputString() must return 'reset'. If 'reset' is returned it other states (like state 1 or 7), it does not mean the final condition
	will be met. This is because it only has to be met after the 9th case has been met. Once it returns 'reset', it will print 'error' and exit.

Testing:
	Iteration 76: c = w, s = ser, state = 0
	Iteration 77: c = 1, s =rtrt, state = 0
	Iteration 78: c = +, s = ree, state = 0
	Iteration 79: c = n, s =tr, state = 0
	Iteration 80: c = n, s = eestt, state = 0
	Iteration 81: c = u, s = eresr, state = 0
	Iteration 82: c = [, s = ett, state = 0
	Iteration 83: c = t, s = ttser, state = 1
	Iteration 84: c = D, s = bqlfh, state = 1
	Iteration 85: c = G, s = sse, state = 1
	Iteration 86: c = !, s =tere, state = 1
	Iteration 87: c = d, s = tes, state = 1
	~
	Iteration 101: c = n, s = t, state = 1
	Iteration 102: c = (, s = tst, state = 1
	Iteration 103: c = /, s = ste, state = 2
	Iteration 104: c = X, s =ee, state = 2
	Iteration 105: c = 2, s = rreee, state = 2
	Iteration 106: c = 6, s = srt, state = 2
	Iteration 107: c = B, s = rvqjn, state = 2
	Iteration 108: c = _, s = see, state = 2
	Iteration 109: c = \, s = svyop, state = 2
	Iteration 110: c = =, s = eeeee, state = 2
	Iteration 111: c = x, s = trere, state = 2
	Iteration 112: c = s, s = tee, state = 2
	Iteration 113: c = 3, s = yirqd, state = 2
	Iteration 114: c = 9, s = rteee, state = 2
	Iteration 115: c = @, s = tet, state = 2
	Iteration 116: c = }, s =ss, state = 2
	Iteration 117: c = +, s = rtets, state = 2
	Iteration 118: c = ,, s = eesse, state = 2
	Iteration 119: c = o, s = sts, state = 2
	~
	Iteration 150: c = D, s = ssr, state = 2
	Iteration 151: c = P, s = ttses, state = 2
	Iteration 152: c = ^, s = eesse, state = 2
	Iteration 153: c = k, s = tsert, state = 2
	Iteration 154: c = k, s =erre, state = 2
	Iteration 155: c = \, s = jhrlx, state = 2
	Iteration 156: c = T, s =rset, state = 2
	Iteration 157: c = Z, s = trrwz, state = 2
	Iteration 158: c = /, s = sre, state = 2
	Iteration 159: c = f, s = ttsee, state = 2
	Iteration 160: c = R, s = kavys, state = 2
	Iteration 161: c = {, s = retrr, state = 2
	Iteration 162: c = i, s = vmajc, state = 3
	Iteration 163: c = V, s =stet, state = 3
	Iteration 164: c = M, s = e, state = 3
	~
	Iteration 1211: c = F, s = lzhej, state = 9
	Iteration 1212: c = +, s = tvxdg, state = 9
	Iteration 1213: c = /, s = rer, state = 9
	Iteration 1214: c = Z, s =sree, state = 9
	Iteration 1215: c = w, s =esre, state = 9
	Iteration 1216: c = 9, s = rrete, state = 9
	Iteration 1217: c = Q, s = srese, state = 9
	Iteration 1218: c = 5, s =, state = 9
	Iteration 1219: c = I, s = ssest, state = 9
	Iteration 1220: c = s, s = blhlb, state = 9
	Iteration 1221: c = V, s = eeeer, state = 9
	Iteration 1222: c = $, s = ers, state = 9
	Iteration 1223: c = z, s = ssess, state = 9
	Iteration 1224: c = 5, s = tee, state = 9
	Iteration 1225: c = ., s = ertrr, state = 9
	Iteration 1226: c = g, s = reset, state = 9
