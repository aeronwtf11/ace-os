<div align="center">

<img src="assets/aceos.png" width="150" alt="AceOS">

# AceOS


---

</div>

## what is AceOS?

AceOS is my attempt at building an operating system and learning how things actually work underneath the software we use every day.

The long-term goal is to develop an OS with its own kernel, userspace, system utilities, and eventually a desktop environment.

I'm starting with a Linux-based experimental system to learn about boot processes, system initialization, filesystems, and low-level development before tackling my own kernel.

This is a personal project, and I'm figuring things out as I go.

## current status

**early development — pre-alpha**

Right now, I'm working on getting a minimal Linux-based system running on a Raspberry Pi 4.

The first milestone is simple: boot into a working shell on real hardware.

No fancy desktop, no unnecessary features. Just a working system.

## technical overview

| Component | Technology |
|---|---|
| Initial architecture | ARM64 |
| Initial hardware | Raspberry Pi 4 |
| Build system | Buildroot |
| Current kernel base | Linux |
| Future kernel | Custom, written in C |
| Filesystem | ext4 |
| Init system | OpenRC (planned) |
| Shell | Bash (planned) |
| Package manager | Custom (planned) |

These choices may change as the project evolves.

## goals

- Build a bootable system for real hardware.
- Understand and control the boot process.
- Develop my own system utilities.
- Experiment with a rule-based configuration system.
- Create a custom package manager.
- Eventually build a desktop environment.
- Research kernel development and write my own kernel.

I want AceOS to be something I actually understand, not just a collection of software with a different name.

## roadmap

- [ ] **0.1 — First Boot:** Boot a minimal ARM64 Linux system on the Raspberry Pi 4.
- [ ] **0.2 — Userspace:** Set up a usable shell, basic utilities, and initialization.
- [ ] **0.3 — System Management:** Start developing AceOS-specific commands and configuration.
- [ ] **0.4 — Networking:** Add basic networking and system services.
- [ ] **0.5 — Packages:** Experiment with a custom package manager.
- [ ] **Later — Desktop:** Build a graphical environment.
- [ ] **Long-term — Kernel:** Research and develop an independent kernel.

This isn't a release schedule. It's just where I want to take the project.

## development

AceOS is currently being developed and tested using Linux.

The initial build process uses Buildroot to assemble a minimal system for ARM64.

Source code, build instructions, and configuration files will be documented here as the project develops.

**Do not expect a usable daily-driver OS yet.**

## related projects

**[AceNix](https://github.com/aeronwtf11/AceNix)** — My NixOS management CLI.

**AceLinux** — A separate Linux distribution project.

AceOS is my longer-term operating system development project, with the goal of eventually moving beyond the Linux kernel.

---

<div align="center">

<sub>built out of curiosity, probably a questionable amount of it.</sub>

</div>
