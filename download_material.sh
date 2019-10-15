CURDIR=$(pwd)

# install gdrive
echo "[INFO] Checking if gdrive is installed..."
if ! [ -x "$(command -v gdrive)" ]
then
    echo "[INFO] gdrive wasn't found. Installing..."
    cd /tmp
    wget https://github.com/gdrive-org/gdrive/releases/download/2.1.0/gdrive-linux-x64 -O gdrive
    chmod +x gdrive
    sudo mv gdrive ~/.local/bin
    cd $CURDIR
else
    echo "[INFO] gdrive was found."
fi

# download material
echo "[INFO] Downloading material..."
gdrive download -r 1jehUgWzW8KwWv_t5_A4Iv73LeUr4uwsh

echo "[INFO] Renaming Материал to Material."
mv Материал Material
echo "[INFO] Done."
