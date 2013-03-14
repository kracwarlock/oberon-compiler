MODULE S3Set;

(* Read a file of integers from standard 
   input and print the total *)

IMPORT In, Out;

CONST MAX = 10;

VAR 
  k, N, x, total: INTEGER;
  s1, s2: SET;
  pints: ARRAY MAX OF INTEGER;

BEGIN
  s1 := {1,2};
  total := MAX(s1);
  Out.Int(total,0); Out.Ln;
END S3Set.