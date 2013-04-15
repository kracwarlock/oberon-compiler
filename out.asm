main:
li	$t0,0
sw	$t0,12($sp)
li	$t0,1
sw	$t0,16($sp)
li	$t0,3
sw	$t0,20($sp)
li	$t0,10
sw	$t0,24($sp)
li	$t0,1
sw	$t0,28($sp)

L0:
lw	$t7,20($sp)
lw	$t8,24($sp)
ble	$t7,$t8,M0
li	$t9,0
b	End0

M0:
li	$t9,1

End0:
beqz	$t9,L1
lw	$t0,20($sp)
addiu	$t1,$t0,1
sw	$t1,32($sp)
lw	$t0,32($sp)
sw	$t0,20($sp)
lw	$t0,16($sp)
sw	$t0,28($sp)
lw	$t0,12($sp)
lw	$t1,16($sp)
add	$t2,$t1,$t0
sw	$t2,36($sp)
lw	$t0,36($sp)
sw	$t0,16($sp)
lw	$t0,28($sp)
sw	$t0,12($sp)
b	L0

L1:
lw	$t0,16($sp)
sw	$t0,16($sp)
li	$v0,10
syscall