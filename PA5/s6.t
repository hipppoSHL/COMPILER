foo:
	BeginFunc
	s = 0
	_t0 = s
	i = 0
	_t1 = i
L0:
	_t2 = i < 10
	IFZ _t2 Goto L1
	j = 0
	_t3 = j
L2:
	IFZ 1 Goto L3
	_t4 = i * 4
	_t5 = a + _t4
	_t6 = j * 4
	_t7 = b + _t6
	_t8 = *(_t5) * *(_t7)
	s = s + _t8
	_t9 = s
	j = j + 1
	_t10 = j == 10
	IFZ _t10 Goto L4
	Goto L3
L4: 
	Goto L2
L3: 
	_t11 = i * 4
	_t12 = a + _t11
	_t13 = *(_t12) == 0
	IFZ _t13 Goto L5
	Goto L1
L5: 
	_t14 = i
	i = i + 1
	Goto L0
L1: 
	Return s
	EndFunc
main:
	BeginFunc
	i = 0
	_t15 = i
L6:
	_t16 = i < 10
	IFZ _t16 Goto L7
	_t17 = i * 4
	_t18 = x + _t17
	_t19 = 2 * i
	_t20 = _t19 - 1
	*(_t18) = _t20
	_t21 = *(_t18)
	_t22 = i * 4
	_t23 = y + _t22
	_t24 = i * 4
	_t25 = x + _t24
	*(_t23) = *(_t25)
	_t26 = *(_t23)
	_t27 = i * 4
	_t28 = y + _t27
	_t29 = i * 4
	_t30 = y + _t29
	_t31 = *(_t28) *= *(_t30)
	_t32 = i
	i = i + 1
	Goto L6
L7: 
	PushParam y
	PushParam x
	_t33 = LCall foo
	PopParam 8
	PushParam _t33
	_t34 = LCall print
	PopParam 4
	Return 0
	EndFunc
