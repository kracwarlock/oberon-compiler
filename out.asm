main:
li	$t0,7
sw	$t0,12($sp)
li	$t0,0
sw	$t0,16($sp)
li	$t0,0
sw	$t0,20($sp)

L0:
lw	$t9,12($sp)
blt	$t9,10,M0
li	$t9,0
b	End0

M0:
li	$t9,1

End0:
beqz	$t9,L1

L2:
lw	$t7,16($sp)
lw	$t8,12($sp)
ble	$t7,$t8,M1
li	$t9,0
b	End1

M1:
li	$t9,1

End1:
beqz	$t9,L3
lw	$t0,16($sp)
addiu	$t1,$t0,1
sw	$t1,24($sp)
lw	$t0,24($sp)
sw	$t0,16($sp)
b	L2

L3:
lw	$t0,12($sp)
addiu	$t1,$t0,1
sw	$t1,32($sp)
lw	$t0,32($sp)
sw	$t0,12($sp)
b	L0

L1:
li	$v0,10
syscall