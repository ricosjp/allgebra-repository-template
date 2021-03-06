Template for HPC Project
========================

🚀 HPC Development Ready 🚀

Features
---------

- **Uniform**, **Reproducible** setup of HPC development environment using container
- [CUDA][cuda], [Intel MKL][intel-mkl] integration, and [OpenMP Offloading][openmp-offloading] / [OpenACC][openacc] enabled compilers ([GCC][gcc-openmp-offloading], [Clang][llvm-openmp-offloading]) in a container
- [GitHub Actions][github-actions] with container and [Visual Studio Code][vscode] [Remote Container][remote-container] exntension settings

[ricosjp/allgebra](https://github.com/ricosjp/allgebra) is a project of development containers for HPC developer,
and this repository is its sub-project.

[remote-container]: https://github.com/microsoft/vscode-dev-containers
[vscode]: https://github.com/microsoft/vscode
[github-actions]: https://docs.github.com/en/actions
[cuda]: https://developer.nvidia.com/cuda-toolkit
[intel-mkl]: https://software.intel.com/content/www/us/en/develop/documentation/oneapi-mkl-dpcpp-developer-reference/top.html
[openmp-offloading]: https://www.openmp.org/updates/openmp-accelerator-support-gpus/
[openacc]: https://www.openacc.org/
[gcc-openmp-offloading]: https://gcc.gnu.org/wiki/Offloading
[llvm-openmp-offloading]: https://openmp.llvm.org/index.html

Create new repository
----------------------

- Login to GitHub
- Push "Use this template" button ↗️

See also [GitHub Document](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-repository-from-a-template)

Install Docker with NVIDIA container toolkit
---------------------------------------------

### For Linux

Install [docker engine][docker], [docker compose][docker-compose] and [NVIDIA container toolkit][nvidia-container-toolkit]

[docker]: https://docs.docker.com/engine/
[docker-compose]: https://docs.docker.com/compose/
[nvidia-container-toolkit]: https://github.com/NVIDIA/nvidia-docker

### For Windows 11 (CUDA on WSL2)

- Install [NVIDIA Drivers for CUDA on WSL, including DirectML Support](https://developer.nvidia.com/cuda/wsl/download)
- Install [Docker Desktop for Windows](https://hub.docker.com/editions/community/docker-ce-desktop-windows)
  - Confirm docker working in WSL2 mode instead of Hyper-V mode

Then you can run `docker` command on cmd.exe or PowerShell

```
docker run -it --rm --gpus=all ghcr.io/ricosjp/allgebra/cuda11_4/clang12/mkl:21.09.0
```

[WIP]: https://insider.windows.com/

Windows 10 is not supported because we cannot handle NVIDIA GPU managed by Windows kernel from WSL2.
Please upgrade to Windows 11.

VSCode setup
-------------

- Clone your repository
- Open the directory by [Visual Studio Code][vscode]
- Install [Remote Container][remote-container] extension
- Click the lower left `><` green button in vscode UI
- Select "Reopen in Container"
- Select "From docker-compose.yml"
  - Then the `docker pull` starts. This will download the allgebra container, which is very large (~8GB) because it contains CUDA and Intel MKL binaries.
  - You can see the downloading log in the vscode's terminal
- If everything goes well, a new vscode window opens with Remote Container extension.
  - Run `nvidia-smi` to confirm the GPUs are accessible

### Use host SSH key in container

VSCode will expose host's ssh-agent socket into container process, and you can use host SSH key in container.
See the [official document of vscode](https://code.visualstudio.com/docs/remote/troubleshooting#_setting-up-the-ssh-agent) for detail.
Roughly,

- Start host ssh-agent process
  - In Windows, you can check if ssh-agent starts by `Get-Service ssh-agent`
- `ssh-add` host key to host ssh-agent
  - When the key is correctly added, `ssh-add -l` command shows the registered key.
- (Re)start Remote Container
  - The path of socket connecting to host ssh-agent is written in `$SSH_AUTH_SOCK` env variable
  - `ssh-add -l` command shows the key registerred on the host

### Recommended Extensions

- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
- [Nsight Visual Studio Code Edition](https://marketplace.visualstudio.com/items?itemName=NVIDIA.nsight-vscode-edition)
