VSCode Remote Container example for allgebra containers 
=======================================================

[ricosjp/allgebra](https://github.com/ricosjp/allgebra) is a project for serving base development containers for HPC users.
This repository is its sub-project, and shows how to use it with the extension [Remote Container][remote-container] of [Visual Studio Code][vscode].

[remote-container]: https://github.com/microsoft/vscode-dev-containers
[vscode]: https://github.com/microsoft/vscode

For Linux
----------
Install docker engine and nvidia toolkit

For Windows 11 (Windows Insider Program)
----------------------------------------

In order to use CUDA on WSL2, you have to use the build distributed by [Windows Insider Program](https://insider.windows.com/).

- Enable [Windows 10 Insider Preview][WIP] with beta channel, and run Windows Update
- Install [NVIDIA Drivers for CUDA on WSL, including DirectML Support](https://developer.nvidia.com/cuda/wsl/download)
- Install [Docker Desktop for Windows](https://hub.docker.com/editions/community/docker-ce-desktop-windows)
  - Use WSL mode instead of Hyper-V mode

Then you can run `docker` command on cmd.exe or PowerShell

```
docker run -it --rm --gpus=all ghcr.io/ricosjp/allgebra/cuda11_4/clang12/mkl:21.09.0
```

How to use
----------

Here, we start setup vscode remote container extension:

- Clone this repository
- Open the cloned directory by [Visual Studio Code][vscode]
- Install [Remote Container][remote-container] extension
- Click the lower left `><` green button in vscode UI
- Select "Reopen in Container"
- Select "From docker-compose.yml"
  - Then the `docker pull` starts. This will download the allgebra container, which is very large (~8GB) because it contains CUDA and Intel MKL binaries.
  - You can see the downloading log in the vscode's terminal
- If everything goes well, a new vscode window opens with Remote Container extension.
  - Open Terminal, and run `clang --version`