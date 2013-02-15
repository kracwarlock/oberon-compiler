MODULE S1power;

(* Compute x ** n using the obvious O(n) algorithm *)

IMPORT Out, Args, Conv;

VAR
  x, y: REAL;
  k, n: INTEGER;
  buf: ARRAY 256 OF CHAR;

BEGIN
  (* Get values of x and n from the command line *)
  IF (Args.argc # 3) THEN 
    Out.Ln;
    HALT(1);
  END;

  Args.GetArg(1, buf);
  x := Conv.RealVal(buf);
  Args.GetArg(2, buf);
  n := Conv.IntVal(buf);
  (* Compute y = x ** n *)
  k := 0; 
  y := 1;
  WHILE k < n DO
    y := y * x;
    k := k + 1;
  END;

  (* Output y *)
  Out.Real(y); Out.Ln;
END S1power.