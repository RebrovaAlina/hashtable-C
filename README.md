# hashtable-C
Выполнение ./utest
user@s87307:~/home1$ ./utest 
Node: Slon, 2300
Node: Slon, 2300
No such element
Node: Slon, 2300
Can't delete the element
Выполнение gcov
user@s87307:~/home1$ gcov hashtable.c 
File 'hashtable.c'
Lines executed:93.02% of 43
Creating 'hashtable.c.gcov'
Выполнение valgrind
user@s87307:~/home1$ valgrind ./utest 
==14422== Memcheck, a memory error detector
==14422== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==14422== Using Valgrind-3.12.0.SVN and LibVEX; rerun with -h for copyright info
==14422== Command: ./utest
==14422== 
Node: Slon, 2300
Node: Slon, 2300
No such element
Node: Slon, 2300
Can't delete the element
==14422== 
==14422== HEAP SUMMARY:
==14422==     in use at exit: 72 bytes in 3 blocks
==14422==   total heap usage: 8 allocs, 5 frees, 2,257 bytes allocated
==14422== 
==14422== LEAK SUMMARY:
==14422==    definitely lost: 0 bytes in 0 blocks
==14422==    indirectly lost: 0 bytes in 0 blocks
==14422==      possibly lost: 0 bytes in 0 blocks
==14422==    still reachable: 72 bytes in 3 blocks
==14422==         suppressed: 0 bytes in 0 blocks
==14422== Rerun with --leak-check=full to see details of leaked memory
==14422== 
==14422== For counts of detected and suppressed errors, rerun with: -v
==14422== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
