<div align="center">

<img src="assets/aceos.png" width="155" alt="AceOS Logo">

# AceOS

**An operating system built on our own terms.**

`x86-64` · `C` · `OS Development` · `Systems Programming`

**One System. Our Decisions.**

---

</div>

## Overview

AceOS is an experimental, general-purpose operating system project focused on system architecture, low-level programming, and giving users meaningful control over their computers.

We're building AceOS to explore how operating systems work, from the boot process and kernel interfaces to initialization, system utilities, configuration management, and eventually a graphical environment.

Our goal is to create a coherent operating system rather than simply assemble unrelated software components.

AceOS is designed with ordinary desktop and laptop computers in mind, initially targeting the x86-64 architecture.

The project will be developed incrementally, with each major component designed, implemented, and tested before depending on it elsewhere.

**AceOS is currently in early development. It is not a production-ready operating system.**

## Project status

**Development stage: Pre-alpha**

Our initial objective is to establish a reliable boot process and a minimal userspace environment for x86-64 systems.

| Component | Status |
|---|---|
| System architecture | Planning and design |
| x86-64 support | Initial target |
| UEFI boot | Planned |
| Linux-based development foundation | Planned |
| AceIt init system | Planned |
| Base userspace | Planned |
| Configuration system | Design phase |
| Package manager | Planned |
| User management | Planned |
| Networking | Planned |
| Graphical environment | Long-term |
| Independent kernel | Long-term |

These statuses describe our current development objectives, not completed features.

## Design principles

### Simplicity

We want AceOS to be understandable and predictable.

System configuration should be straightforward, errors should be useful, and software components should have clearly defined responsibilities.

### Modularity

Major subsystems should be designed with well-defined interfaces.

Where practical, components should remain independent so they can be maintained, replaced, and tested separately.

### User control

Users should be able to control their system without unnecessary restrictions or hidden behavior.

### Privacy

AceOS is intended to operate without telemetry or unnecessary network communication by default.

### Reliability

Configuration changes should be validated before application. Recoverable failures should not require reinstalling the entire system.

---

## System architecture

AceOS is planned around several interconnected components.

```text
                      AceOS
                        |
                 Boot Environment
                    (UEFI)
                        |
                      Kernel
                        |
                      AceIt
                  Init System
                        |
              Base System Services
                        |
                  AceOS Userspace
            /           |            \
        Utilities    Configuration   Shell
            \           |            /
                 System Manager
                        |
            Package and User Management
                        |
                 User Environment
                        |
              Optional Desktop Layer
```

### Kernel

The kernel provides the fundamental interfaces required by userspace.

These include process execution, memory management, scheduling, hardware access, and filesystem operations.

During early development, we may use the Linux kernel to prototype our userspace and system-management components.

Our long-term objective is to develop an independent kernel.

The architecture should avoid unnecessary coupling between AceOS-specific userspace tools and a particular kernel implementation.

### AceIt — our init system

**AceIt is the dedicated initialization and service-management system for AceOS.**

It is intended to initialize the operating system after the kernel starts and manage the services required for a usable system.

The initial design responsibilities include:

- Starting essential system services.
- Managing service dependencies and startup order.
- Tracking service states.
- Supporting service start, stop, and restart operations.
- Reporting service failures.
- Providing clear system startup diagnostics.
- Supporting orderly shutdown and reboot procedures.

We intend to keep AceIt understandable, lightweight, and maintainable.

A possible future command interface:

```sh
aceit status
aceit list
aceit start networking
aceit stop networking
aceit restart networking
aceit enable networking
aceit disable networking
```

These commands represent our proposed interface and are not yet implemented.

AceIt will be developed as a distinct subsystem with its own documented architecture and tests.

### Userspace

The AceOS userspace will contain the utilities and interfaces needed to operate the system.

Our initial development priorities include:

- A usable command-line environment.
- Basic filesystem utilities.
- User and permission management.
- Process inspection.
- System information and diagnostics.
- Configuration management.
- Basic networking utilities.

We intend to implement our own AceOS-specific tools while using established software where appropriate during development.

---

## Target platforms

AceOS is designed for general-purpose computers.

| Platform | Priority |
|---|---|
| x86-64 desktop computers | Primary |
| x86-64 laptops | Primary |
| UEFI systems | Initial boot target |
| Legacy BIOS | Potential future support |
| ARM64 computers | Possible future port |
| Virtual machines | Development and testing |

Our architecture should support adding platforms without redesigning the entire operating system.

### Hardware compatibility

Initial testing will focus on virtual machines and selected physical x86-64 computers.

Broader hardware support will depend on the available kernel, drivers, boot infrastructure, and implemented userspace components.

We will document confirmed hardware compatibility rather than assume a successful build works on every computer.

---

## AceOS configuration system

We want system management to be accessible without sacrificing advanced functionality.

A proposed central configuration file is:

```text
/etc/ace/config.sys
```

Example:

```ini
[system]
hostname:ace-pc
network:true
bluetooth:false
desktop:false

[services]
ssh:false

[packages]
pkg.git:true
pkg.vim:true
```

Our intended CLI follows a rule-based approach:

```sh
aceos status
aceos setr hostname:ace-pc
aceos setr network:true
aceos preview
aceos apply
```

### Configuration workflow

1. Read the current configuration.
2. Parse and validate requested rules.
3. Identify which system components are affected.
4. Generate a preview of pending changes.
5. Apply supported changes using the relevant subsystem.
6. Record results and report errors.

The configuration system should communicate with AceIt for service-related operations rather than bypassing the init system.

**The command interface and configuration format are currently design specifications.**

## Package management

AceOS is planned to include a custom binary package manager.

Rather than relying on users to manually compile and install every application, it should eventually provide a consistent way to manage software.

Planned operations include:

```sh
aceos install firefox
aceos remove firefox
aceos search firefox
aceos update
```

Our package-management goals include dependency resolution, package metadata, integrity verification, explicit upgrades, and recovery from failed operations.

The initial system may use preassembled packages while the custom package manager is under development.

## Filesystem layout

We intend to follow familiar Unix filesystem conventions with dedicated locations for AceOS-specific components.

Proposed layout:

```text
/
├── boot/
├── dev/
├── etc/
│   └── ace/
│       └── config.sys
├── home/
├── proc/
├── run/
├── sys/
├── usr/
│   └── bin/
└── var/
    ├── lib/
    │   └── ace/
    └── log/
```

The initial root filesystem is expected to use ext4.

We will finalize the directory structure as the kernel, userspace, and service-management interfaces become more concrete.

---

## Building AceOS

### Development environment

Our primary development platform is Linux, with support for building and testing AceOS on x86-64 hosts.

The planned toolchain includes:

| Tool | Purpose |
|---|---|
| GCC / Clang | C compilation |
| GNU Make | Build automation |
| Git | Source control |
| QEMU | Virtual-machine testing |
| GDB | Debugging |
| GNU Binutils | Low-level development tools |
| Buildroot | Possible early Linux-based system construction |

### Development workflow

We will initially use virtual machines to test new images and system components without putting a development machine's existing operating system at risk.

The planned workflow is:

```text
Source Code
     |
     v
Build System
     |
     v
Bootable Image
     |
     v
QEMU / Test Machine
     |
     v
Boot Verification
     |
     v
Debugging and Testing
```

### Build instructions

Reproducible build commands will be added once the initial build configuration and toolchain are committed.

We will document the exact compiler versions, dependencies, image formats, build options, and test environments used for verified builds.

We do not yet provide an officially verified, bootable AceOS image.

---

## Development roadmap

### Phase 1 — Boot Foundation

- [ ] Finalize the initial x86-64 development environment.
- [ ] Set up reproducible builds.
- [ ] Establish an initial UEFI boot workflow.
- [ ] Produce a bootable system image.
- [ ] Successfully boot inside QEMU.
- [ ] Reach a basic userspace environment.
- [ ] Document the boot process.

### Phase 2 — AceIt

- [ ] Define the AceIt architecture.
- [ ] Implement initial system startup.
- [ ] Create the service definition format.
- [ ] Implement service execution and monitoring.
- [ ] Add service dependency handling.
- [ ] Support orderly shutdown and reboot.
- [ ] Test startup failures and recovery behavior.

### Phase 3 — Base Userspace

- [ ] Establish the filesystem layout.
- [ ] Integrate a shell and essential utilities.
- [ ] Implement basic user management.
- [ ] Create AceOS system information tools.
- [ ] Implement diagnostics and logging.
- [ ] Connect base services to AceIt.

### Phase 4 — Configuration Management

- [ ] Finalize the rule format.
- [ ] Implement the configuration parser.
- [ ] Add validation and error reporting.
- [ ] Develop the `aceos` CLI.
- [ ] Implement preview and apply.
- [ ] Integrate configuration with AceIt.
- [ ] Introduce backup and recovery mechanisms.

### Phase 5 — Networking and Packages

- [ ] Establish basic network connectivity.
- [ ] Integrate network services with AceIt.
- [ ] Design the binary package format.
- [ ] Implement package installation and removal.
- [ ] Support dependency management.
- [ ] Add package updates and integrity verification.

### Phase 6 — Desktop Environment

- [ ] Establish a graphical session.
- [ ] Develop desktop-management components.
- [ ] Implement basic window management.
- [ ] Add graphical configuration tools.
- [ ] Improve hardware compatibility.
- [ ] Explore additional architectures.

### Long-term — Independent Kernel

- [ ] Research kernel bootstrapping.
- [ ] Establish a freestanding C development environment.
- [ ] Implement initial kernel entry and diagnostics.
- [ ] Research memory management.
- [ ] Implement process management and scheduling.
- [ ] Design system calls.
- [ ] Develop essential hardware interfaces.
- [ ] Investigate userspace compatibility.
- [ ] Bring up AceOS userspace on our own kernel.

The kernel roadmap is exploratory and does not imply a fixed release date.

---

## Testing

Our testing approach will distinguish between successful compilation, virtual-machine testing, and actual hardware verification.

| Test | Purpose |
|---|---|
| Unit tests | Validate individual components |
| Integration tests | Verify interaction between subsystems |
| Boot tests | Check that an image starts correctly |
| AceIt tests | Validate startup and service management |
| Filesystem tests | Detect storage-related problems |
| Configuration tests | Validate parsing and applying rules |
| Recovery tests | Verify expected failure handling |
| Hardware tests | Establish real compatibility |

A system image is not considered verified solely because the build process completed successfully.

## Security and privacy

AceOS is intended to follow secure-by-default principles wherever practical.

Our goals include minimal default services, explicit privileges, no telemetry, verified software updates, and documented trust boundaries.

During early development, we will treat AceOS as experimental software. It should not be relied upon to protect important data or provide production-level security.

## Project structure

A possible future repository structure:

```text
AceOS/
├── README.md
├── assets/
│   └── aceos.png
├── boot/
├── kernel/
├── init/
│   └── aceit/
├── userspace/
├── system/
│   ├── configuration/
│   ├── services/
│   └── packages/
├── build/
├── tests/
└── docs/
    ├── ARCHITECTURE.md
    ├── BUILDING.md
    ├── ACEIT.md
    ├── CONFIGURATION.md
    └── ROADMAP.md
```

This structure is a design proposal and will evolve as development progresses.

## Contributing

AceOS is a team-driven project.

We welcome technical feedback, documentation improvements, code reviews, and contributions.

We prefer understandable, well-documented implementations over unnecessary complexity.

Major changes should describe their purpose, architecture, affected components, and testing requirements.

## Related projects

**[AceNix](https://github.com/aeronwtf11/AceNix)** — Our NixOS management CLI, developed to simplify native NixOS administration.

**AceLinux** — Our separate Linux distribution project.

**AceOS** focuses on long-term operating-system engineering, including our own initialization system and eventual kernel development.

## License

Licensing will be finalized before an official source release.

Until a license is added, no permission to modify or redistribute the source should be assumed.

---

<div align="center">

**AceOS**

*One System. Our Decisions.*

<sub>Built to understand the system, not just use it.</sub>

</div>
