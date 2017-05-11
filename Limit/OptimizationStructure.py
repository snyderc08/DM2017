import os
import shutil
import fileinput



OriginalFile='Codex.cpp'

def create_ConfogFile(mt,met):
    
    print '<bin file="Codex%s%s.cpp"'%(mt,met) + '  name="Codex%s%s"></bin>'%(mt,met)
    NewName='Codex%s%s.cpp'%(mt,met)
    


    shutil.copy (OriginalFile,NewName)
    for line in fileinput.input(NewName,inplace=1):
        if 'aux_shapes' in line:
            line=line.replace('_MT100_MET100',mt+met)
        if 'outputCodex' in line:
            line=line.replace('_MT100_MET100',mt+met)
        print(line.strip())




Met_Cat= ["_MET100","_MET200", "_MET300","_MET400", "_MET500", "_MET600"]
MT_Cat = ["_MT100", "_MT200","_MT300","_MT400", "_MT500", "_MT600"]


grdPack_Generate=open("create_dir.sh","w")
for met in Met_Cat:
    for mt in MT_Cat:
        create_ConfogFile(mt,met)
        grdPack_Generate.write('Codex%s%s\n'%(mt,met))
        grdPack_Generate.write('cp run_rhw.sh outputCodex/Codex%s%s/.\n'%(mt,met))
        grdPack_Generate.write('cd outputCodex/Codex%s%s/.\n'%(mt,met))
        grdPack_Generate.write('sh run_rhw.sh\n')
        grdPack_Generate.write('cd ../../. \n')
grdPack_Generate.close()
