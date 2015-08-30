[Problem Link](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2955)

I didn't use suffix array.

(1) Scan input-string. And push all index in vector array indexing with alphbet order.

(2) And scan vector array pushing custom priority queue(order by 1. length and 2. length*count).

(3) So we can find best(longest length and length*count) repeated string.

(4) Next, pop best string from priority queue. and then check all next index of string pushing vector array. Keep go (2)