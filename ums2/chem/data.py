import cyaron, os

os.system('g++ -o std -O2 ./std.cpp')

f = [
        ['C+O=CO', '2O3=3O2', 'C+O=CO2', '2H2+C=CH4', 'C+O2=CO', 'O2=O3', 'C+N=CN', 'C+N2=CN', '2T+3V=2TV'],
        ['Na+2Cl=NaCl', 'H2+Cl2=2HCl', 'Cu+As=Cs+Au', 'Ba+2Na=BaNa2', 'Ba+Na=BaNa', 'Cl2+NH3=2HCl+HN', 'Pb+Au=PbAu', '6HCl+2Fe=2FeCl3+3H2'],
        ['3Ba(OH)2+2H3PO4=6H2O+Ba3(PO4)2', '4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O', 'CaCl2+2AgNO3=Ca(NO3)2+AgCl', '3Mg(OH)2+4CO2=Mg3C4+3H2O+3O2', '2HNO3+Fe=Fe(NO3)2+H2', '2Al(OH)3+3H2SO4=Al2(SO4)3+3H2O'],
        ['4Au+8NaCN+2H2O+O2=4Na(Au(CN)2)+4NaOH', '3Au+4H2O+7NaCl=4Na(Au(CN)2)+4NaOH']
    ]

for i in range(10):

    io = cyaron.IO(file_prefix = 'chem', data_id = i + 1)
    if i < 2:
        ff = f[0]
    elif i < 5:
        ff = f[0] + f[1]
    elif i < 8:
        ff = f[0] + f[1] + f[2]
    else:
        ff = f[0] + f[1] + f[2] + f[3]
    n = cyaron.randint(7, len(ff))
    io.input_writeln(n)
    for j in range(n):
        io.input_writeln(cyaron.choice(ff))
    io.output_gen('./std')
    print('data{} generated'.format(i + 1))
