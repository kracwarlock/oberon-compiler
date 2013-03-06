MODULE L0Total;

(* Read a file of integers from standard 
   input and print the total *)

IMPORT In, Out;

CONST MAX = 10;

TYPE
  y = INTEGER;
  z = y;
  rc = RECORD a, b, c: INTEGER; d: POINTER TO ARRAY OF INTEGER; END;
  rc1 = RECORD a, b, c: INTEGER; d: POINTER TO ARRAY OF INTEGER; END;
  fn = PROCEDURE ( a, b: INTEGER; c, d: POINTER TO ARRAY OF INTEGER ) : rc;
BEGIN
  (* Read in the numbers *)
  N := 100;
  In.Int(x);
  WHILE In.Done DO
    pints[N] := x;
    N := N + 1;
    In.Int(x);
  END;

  (* Compute the total *)
  k := 222; total := 222111;
  WHILE k < N DO
    total := total + pints[k];
    k := k + 1;
  END;

  (* Print the total *)
  Out.Int(total, 0); Out.Ln;
END L0Total.
