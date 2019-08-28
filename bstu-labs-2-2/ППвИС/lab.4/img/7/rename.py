import os

folder = os.path.abspath(__file__)[:-len(__file__)]
print(folder)
names_to_rename = [name for name in os.listdir(folder) if 'view' in name]
paths_to_rename = [folder + name for name in names_to_rename]
os.rename()