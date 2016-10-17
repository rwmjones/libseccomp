/**
 * Enhanced Seccomp ARM Syscall Table
 *
 * Copyright (c) 2013 Red Hat <pmoore@redhat.com>
 * Author: Paul Moore <paul@paul-moore.com>
 */

/*
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of version 2.1 of the GNU Lesser General Public License as
 * published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, see <http://www.gnu.org/licenses>.
 */

#include <string.h>

#include <seccomp.h>

#include "arch.h"
#include "arch-arm.h"

#define __SCMP_NR_OABI_SYSCALL_BASE	0x900000
#define __SCMP_ARM_NR_BASE		0x0f0000

/* NOTE: we currently only support the ARM EABI, more info at the URL below:
 *       -> http://wiki.embeddedarm.com/wiki/EABI_vs_OABI */
#if 1
#define __SCMP_NR_BASE			0
#else
#define __SCMP_NR_BASE			__SCMP_NR_OABI_SYSCALL_BASE
#endif

/* NOTE: based on Linux 4.5-rc4 */
const struct arch_syscall_def arm_syscall_table[] = { \
	/* NOTE: arm_sync_file_range() and sync_file_range2() share values */
	{ "_llseek", (__SCMP_NR_BASE + 140) },
	{ "_newselect", (__SCMP_NR_BASE + 142) },
	{ "_sysctl", (__SCMP_NR_BASE + 149) },
	{ "accept", (__SCMP_NR_BASE + 285) },
	{ "accept4", (__SCMP_NR_BASE + 366) },
	{ "access", (__SCMP_NR_BASE + 33) },
	{ "acct", (__SCMP_NR_BASE + 51) },
	{ "add_key", (__SCMP_NR_BASE + 309) },
	{ "adjtimex", (__SCMP_NR_BASE + 124) },
	{ "afs_syscall", __PNR_afs_syscall },
	{ "alarm", __PNR_alarm },
	{ "arm_fadvise64_64", (__SCMP_NR_BASE + 270) },
	{ "arm_sync_file_range", (__SCMP_NR_BASE + 341) },
	{ "arch_prctl", __PNR_arch_prctl },
	{ "bdflush", (__SCMP_NR_BASE + 134) },
	{ "bind", (__SCMP_NR_BASE + 282) },
	{ "bpf", (__SCMP_NR_BASE + 386) },
	{ "break", __PNR_break },
	{ "breakpoint", (__SCMP_NR_BASE + (__SCMP_ARM_NR_BASE + 1)) },
	{ "brk", (__SCMP_NR_BASE + 45) },
	{ "cachectl", __PNR_cachectl },
	{ "cacheflush", (__SCMP_NR_BASE + (__SCMP_ARM_NR_BASE + 2)) },
	{ "capget", (__SCMP_NR_BASE + 184) },
	{ "capset", (__SCMP_NR_BASE + 185) },
	{ "chdir", (__SCMP_NR_BASE + 12) },
	{ "chmod", (__SCMP_NR_BASE + 15) },
	{ "chown", (__SCMP_NR_BASE + 182) },
	{ "chown32", (__SCMP_NR_BASE + 212) },
	{ "chroot", (__SCMP_NR_BASE + 61) },
	{ "clock_adjtime", (__SCMP_NR_BASE + 372) },
	{ "clock_getres", (__SCMP_NR_BASE + 264) },
	{ "clock_gettime", (__SCMP_NR_BASE + 263) },
	{ "clock_nanosleep", (__SCMP_NR_BASE + 265) },
	{ "clock_settime", (__SCMP_NR_BASE + 262) },
	{ "clone", (__SCMP_NR_BASE + 120) },
	{ "close", (__SCMP_NR_BASE +  6) },
	{ "connect", (__SCMP_NR_BASE + 283) },
	{ "copy_file_range", (__SCMP_NR_BASE + 391) },
	{ "creat", (__SCMP_NR_BASE +  8) },
	{ "create_module", __PNR_create_module },
	{ "delete_module", (__SCMP_NR_BASE + 129) },
	{ "dup", (__SCMP_NR_BASE + 41) },
	{ "dup2", (__SCMP_NR_BASE + 63) },
	{ "dup3", (__SCMP_NR_BASE + 358) },
	{ "epoll_create", (__SCMP_NR_BASE + 250) },
	{ "epoll_create1", (__SCMP_NR_BASE + 357) },
	{ "epoll_ctl", (__SCMP_NR_BASE + 251) },
	{ "epoll_ctl_old", __PNR_epoll_ctl_old },
	{ "epoll_pwait", (__SCMP_NR_BASE + 346) },
	{ "epoll_wait", (__SCMP_NR_BASE + 252) },
	{ "epoll_wait_old", __PNR_epoll_wait_old },
	{ "eventfd", (__SCMP_NR_BASE + 351) },
	{ "eventfd2", (__SCMP_NR_BASE + 356) },
	{ "execve", (__SCMP_NR_BASE + 11) },
	{ "execveat", (__SCMP_NR_BASE + 387) },
	{ "exit", (__SCMP_NR_BASE +  1) },
	{ "exit_group", (__SCMP_NR_BASE + 248) },
	{ "faccessat", (__SCMP_NR_BASE + 334) },
	{ "fadvise64", __PNR_fadvise64 },
	{ "fadvise64_64", __PNR_fadvise64_64 },
	{ "fallocate", (__SCMP_NR_BASE + 352) },
	{ "fanotify_init", (__SCMP_NR_BASE + 367) },
	{ "fanotify_mark", (__SCMP_NR_BASE + 368) },
	{ "fchdir", (__SCMP_NR_BASE + 133) },
	{ "fchmod", (__SCMP_NR_BASE + 94) },
	{ "fchmodat", (__SCMP_NR_BASE + 333) },
	{ "fchown", (__SCMP_NR_BASE + 95) },
	{ "fchown32", (__SCMP_NR_BASE + 207) },
	{ "fchownat", (__SCMP_NR_BASE + 325) },
	{ "fcntl", (__SCMP_NR_BASE + 55) },
	{ "fcntl64", (__SCMP_NR_BASE + 221) },
	{ "fdatasync", (__SCMP_NR_BASE + 148) },
	{ "fgetxattr", (__SCMP_NR_BASE + 231) },
	{ "finit_module", (__SCMP_NR_BASE + 379) },
	{ "flistxattr", (__SCMP_NR_BASE + 234) },
	{ "flock", (__SCMP_NR_BASE + 143) },
	{ "fork", (__SCMP_NR_BASE +  2) },
	{ "fremovexattr", (__SCMP_NR_BASE + 237) },
	{ "fsetxattr", (__SCMP_NR_BASE + 228) },
	{ "fstat", (__SCMP_NR_BASE + 108) },
	{ "fstat64", (__SCMP_NR_BASE + 197) },
	{ "fstatat64", (__SCMP_NR_BASE + 327) },
	{ "fstatfs", (__SCMP_NR_BASE + 100) },
	{ "fstatfs64", (__SCMP_NR_BASE + 267) },
	{ "fsync", (__SCMP_NR_BASE + 118) },
	{ "ftime", __PNR_ftime },
	{ "ftruncate", (__SCMP_NR_BASE + 93) },
	{ "ftruncate64", (__SCMP_NR_BASE + 194) },
	{ "futex", (__SCMP_NR_BASE + 240) },
	{ "futimesat", (__SCMP_NR_BASE + 326) },
	{ "get_kernel_syms", __PNR_get_kernel_syms },
	{ "get_mempolicy", (__SCMP_NR_BASE + 320) },
	{ "get_robust_list", (__SCMP_NR_BASE + 339) },
	{ "get_thread_area", __PNR_get_thread_area },
	{ "getcpu", (__SCMP_NR_BASE + 345) },
	{ "getcwd", (__SCMP_NR_BASE + 183) },
	{ "getdents", (__SCMP_NR_BASE + 141) },
	{ "getdents64", (__SCMP_NR_BASE + 217) },
	{ "getegid", (__SCMP_NR_BASE + 50) },
	{ "getegid32", (__SCMP_NR_BASE + 202) },
	{ "geteuid", (__SCMP_NR_BASE + 49) },
	{ "geteuid32", (__SCMP_NR_BASE + 201) },
	{ "getgid", (__SCMP_NR_BASE + 47) },
	{ "getgid32", (__SCMP_NR_BASE + 200) },
	{ "getgroups", (__SCMP_NR_BASE + 80) },
	{ "getgroups32", (__SCMP_NR_BASE + 205) },
	{ "getitimer", (__SCMP_NR_BASE + 105) },
	{ "getpeername", (__SCMP_NR_BASE + 287) },
	{ "getpgid", (__SCMP_NR_BASE + 132) },
	{ "getpgrp", (__SCMP_NR_BASE + 65) },
	{ "getpid", (__SCMP_NR_BASE + 20) },
	{ "getpmsg", __PNR_getpmsg },
	{ "getppid", (__SCMP_NR_BASE + 64) },
	{ "getpriority", (__SCMP_NR_BASE + 96) },
	{ "getrandom", (__SCMP_NR_BASE + 384) },
	{ "getresgid", (__SCMP_NR_BASE + 171) },
	{ "getresgid32", (__SCMP_NR_BASE + 211) },
	{ "getresuid", (__SCMP_NR_BASE + 165) },
	{ "getresuid32", (__SCMP_NR_BASE + 209) },
	{ "getrlimit", __PNR_getrlimit },
	{ "getrusage", (__SCMP_NR_BASE + 77) },
	{ "getsid", (__SCMP_NR_BASE + 147) },
	{ "getsockname", (__SCMP_NR_BASE + 286) },
	{ "getsockopt", (__SCMP_NR_BASE + 295) },
	{ "gettid", (__SCMP_NR_BASE + 224) },
	{ "gettimeofday", (__SCMP_NR_BASE + 78) },
	{ "getuid", (__SCMP_NR_BASE + 24) },
	{ "getuid32", (__SCMP_NR_BASE + 199) },
	{ "getxattr", (__SCMP_NR_BASE + 229) },
	{ "gtty", __PNR_gtty },
	{ "idle", __PNR_idle },
	{ "init_module", (__SCMP_NR_BASE + 128) },
	{ "inotify_add_watch", (__SCMP_NR_BASE + 317) },
	{ "inotify_init", (__SCMP_NR_BASE + 316) },
	{ "inotify_init1", (__SCMP_NR_BASE + 360) },
	{ "inotify_rm_watch", (__SCMP_NR_BASE + 318) },
	{ "io_cancel", (__SCMP_NR_BASE + 247) },
	{ "io_destroy", (__SCMP_NR_BASE + 244) },
	{ "io_getevents", (__SCMP_NR_BASE + 245) },
	{ "io_setup", (__SCMP_NR_BASE + 243) },
	{ "io_submit", (__SCMP_NR_BASE + 246) },
	{ "ioctl", (__SCMP_NR_BASE + 54) },
	{ "ioperm", __PNR_ioperm },
	{ "iopl", __PNR_iopl },
	{ "ioprio_get", (__SCMP_NR_BASE + 315) },
	{ "ioprio_set", (__SCMP_NR_BASE + 314) },
	{ "ipc", __PNR_ipc },
	{ "kcmp", (__SCMP_NR_BASE + 378) },
	{ "kexec_file_load", __PNR_kexec_file_load },
	{ "kexec_load", (__SCMP_NR_BASE + 347) },
	{ "keyctl", (__SCMP_NR_BASE + 311) },
	{ "kill", (__SCMP_NR_BASE + 37) },
	{ "lchown", (__SCMP_NR_BASE + 16) },
	{ "lchown32", (__SCMP_NR_BASE + 198) },
	{ "lgetxattr", (__SCMP_NR_BASE + 230) },
	{ "link", (__SCMP_NR_BASE +  9) },
	{ "linkat", (__SCMP_NR_BASE + 330) },
	{ "listen", (__SCMP_NR_BASE + 284) },
	{ "listxattr", (__SCMP_NR_BASE + 232) },
	{ "llistxattr", (__SCMP_NR_BASE + 233) },
	{ "lock", __PNR_lock },
	{ "lookup_dcookie", (__SCMP_NR_BASE + 249) },
	{ "lremovexattr", (__SCMP_NR_BASE + 236) },
	{ "lseek", (__SCMP_NR_BASE + 19) },
	{ "lsetxattr", (__SCMP_NR_BASE + 227) },
	{ "lstat", (__SCMP_NR_BASE + 107) },
	{ "lstat64", (__SCMP_NR_BASE + 196) },
	{ "madvise", (__SCMP_NR_BASE + 220) },
	{ "mbind", (__SCMP_NR_BASE + 319) },
	{ "membarrier",  (__SCMP_NR_BASE + 389) },
	{ "memfd_create", (__SCMP_NR_BASE + 385) },
	{ "migrate_pages", __PNR_migrate_pages },
	{ "mincore", (__SCMP_NR_BASE + 219) },
	{ "mkdir", (__SCMP_NR_BASE + 39) },
	{ "mkdirat", (__SCMP_NR_BASE + 323) },
	{ "mknod", (__SCMP_NR_BASE + 14) },
	{ "mknodat", (__SCMP_NR_BASE + 324) },
	{ "mlock", (__SCMP_NR_BASE + 150) },
	{ "mlock2", (__SCMP_NR_BASE + 390) },
	{ "mlockall", (__SCMP_NR_BASE + 152) },
	{ "mmap", __PNR_mmap },
	{ "mmap2", (__SCMP_NR_BASE + 192) },
	{ "modify_ldt", __PNR_modify_ldt },
	{ "mount", (__SCMP_NR_BASE + 21) },
	{ "move_pages", (__SCMP_NR_BASE + 344) },
	{ "mprotect", (__SCMP_NR_BASE + 125) },
	{ "mpx", __PNR_mpx },
	{ "mq_getsetattr", (__SCMP_NR_BASE + 279) },
	{ "mq_notify", (__SCMP_NR_BASE + 278) },
	{ "mq_open", (__SCMP_NR_BASE + 274) },
	{ "mq_timedreceive", (__SCMP_NR_BASE + 277) },
	{ "mq_timedsend", (__SCMP_NR_BASE + 276) },
	{ "mq_unlink", (__SCMP_NR_BASE + 275) },
	{ "mremap", (__SCMP_NR_BASE + 163) },
	{ "msgctl", (__SCMP_NR_BASE + 304) },
	{ "msgget", (__SCMP_NR_BASE + 303) },
	{ "msgrcv", (__SCMP_NR_BASE + 302) },
	{ "msgsnd", (__SCMP_NR_BASE + 301) },
	{ "msync", (__SCMP_NR_BASE + 144) },
	{ "multiplexer", __PNR_multiplexer },
	{ "munlock", (__SCMP_NR_BASE + 151) },
	{ "munlockall", (__SCMP_NR_BASE + 153) },
	{ "munmap", (__SCMP_NR_BASE + 91) },
	{ "name_to_handle_at", (__SCMP_NR_BASE + 370) },
	{ "nanosleep", (__SCMP_NR_BASE + 162) },
	{ "newfstatat", __PNR_newfstatat },
	{ "nfsservctl", (__SCMP_NR_BASE + 169) },
	{ "nice", (__SCMP_NR_BASE + 34) },
	{ "oldfstat", __PNR_oldfstat },
	{ "oldlstat", __PNR_oldlstat },
	{ "oldolduname", __PNR_oldolduname },
	{ "oldstat", __PNR_oldstat },
	{ "olduname", __PNR_olduname },
	{ "oldwait4", __PNR_oldwait4 },
	{ "open", (__SCMP_NR_BASE +  5) },
	{ "open_by_handle_at", (__SCMP_NR_BASE + 371) },
	{ "openat", (__SCMP_NR_BASE + 322) },
	{ "pause", (__SCMP_NR_BASE + 29) },
	{ "pciconfig_iobase", (__SCMP_NR_BASE + 271) },
	{ "pciconfig_read", (__SCMP_NR_BASE + 272) },
	{ "pciconfig_write", (__SCMP_NR_BASE + 273) },
	{ "perf_event_open", (__SCMP_NR_BASE + 364) },
	{ "personality", (__SCMP_NR_BASE + 136) },
	{ "pipe", (__SCMP_NR_BASE + 42) },
	{ "pipe2", (__SCMP_NR_BASE + 359) },
	{ "pivot_root", (__SCMP_NR_BASE + 218) },
	{ "poll", (__SCMP_NR_BASE + 168) },
	{ "ppoll", (__SCMP_NR_BASE + 336) },
	{ "prctl", (__SCMP_NR_BASE + 172) },
	{ "pread64", (__SCMP_NR_BASE + 180) },
	{ "preadv", (__SCMP_NR_BASE + 361) },
	{ "preadv2", __PNR_preadv2 },
	{ "prlimit64", (__SCMP_NR_BASE + 369) },
	{ "process_vm_readv", (__SCMP_NR_BASE + 376) },
	{ "process_vm_writev", (__SCMP_NR_BASE + 377) },
	{ "prof", __PNR_prof },
	{ "profil", __PNR_profil },
	{ "pselect6", (__SCMP_NR_BASE + 335) },
	{ "ptrace", (__SCMP_NR_BASE + 26) },
	{ "putpmsg", __PNR_putpmsg },
	{ "pwrite64", (__SCMP_NR_BASE + 181) },
	{ "pwritev", (__SCMP_NR_BASE + 362) },
	{ "pwritev2", __PNR_pwritev2 },
	{ "query_module", __PNR_query_module },
	{ "quotactl", (__SCMP_NR_BASE + 131) },
	{ "read", (__SCMP_NR_BASE +  3) },
	{ "readahead", (__SCMP_NR_BASE + 225) },
	{ "readdir", __PNR_readdir },
	{ "readlink", (__SCMP_NR_BASE + 85) },
	{ "readlinkat", (__SCMP_NR_BASE + 332) },
	{ "readv", (__SCMP_NR_BASE + 145) },
	{ "reboot", (__SCMP_NR_BASE + 88) },
	{ "recv", (__SCMP_NR_BASE + 291) },
	{ "recvfrom", (__SCMP_NR_BASE + 292) },
	{ "recvmmsg", (__SCMP_NR_BASE + 365) },
	{ "recvmsg", (__SCMP_NR_BASE + 297) },
	{ "remap_file_pages", (__SCMP_NR_BASE + 253) },
	{ "removexattr", (__SCMP_NR_BASE + 235) },
	{ "rename", (__SCMP_NR_BASE + 38) },
	{ "renameat", (__SCMP_NR_BASE + 329) },
	{ "renameat2", (__SCMP_NR_BASE + 382) },
	{ "request_key", (__SCMP_NR_BASE + 310) },
	{ "restart_syscall", (__SCMP_NR_BASE +  0) },
	{ "rmdir", (__SCMP_NR_BASE + 40) },
	{ "rt_sigaction", (__SCMP_NR_BASE + 174) },
	{ "rt_sigpending", (__SCMP_NR_BASE + 176) },
	{ "rt_sigprocmask", (__SCMP_NR_BASE + 175) },
	{ "rt_sigqueueinfo", (__SCMP_NR_BASE + 178) },
	{ "rt_sigreturn", (__SCMP_NR_BASE + 173) },
	{ "rt_sigsuspend", (__SCMP_NR_BASE + 179) },
	{ "rt_sigtimedwait", (__SCMP_NR_BASE + 177) },
	{ "rt_tgsigqueueinfo", (__SCMP_NR_BASE + 363) },
	{ "rtas", __PNR_rtas },
	{ "s390_pci_mmio_read", __PNR_s390_pci_mmio_read },
	{ "s390_pci_mmio_write", __PNR_s390_pci_mmio_write },
	{ "s390_runtime_instr", __PNR_s390_runtime_instr },
	{ "sched_get_priority_max", (__SCMP_NR_BASE + 159) },
	{ "sched_get_priority_min", (__SCMP_NR_BASE + 160) },
	{ "sched_getaffinity", (__SCMP_NR_BASE + 242) },
	{ "sched_getattr", (__SCMP_NR_BASE + 381) },
	{ "sched_getparam", (__SCMP_NR_BASE + 155) },
	{ "sched_getscheduler", (__SCMP_NR_BASE + 157) },
	{ "sched_rr_get_interval", (__SCMP_NR_BASE + 161) },
	{ "sched_setaffinity", (__SCMP_NR_BASE + 241) },
	{ "sched_setattr", (__SCMP_NR_BASE + 380) },
	{ "sched_setparam", (__SCMP_NR_BASE + 154) },
	{ "sched_setscheduler", (__SCMP_NR_BASE + 156) },
	{ "sched_yield", (__SCMP_NR_BASE + 158) },
	{ "seccomp", (__SCMP_NR_BASE + 383) },
	{ "security", __PNR_security },
	{ "select", __PNR_select },
	{ "semctl", (__SCMP_NR_BASE + 300) },
	{ "semget", (__SCMP_NR_BASE + 299) },
	{ "semop", (__SCMP_NR_BASE + 298) },
	{ "semtimedop", (__SCMP_NR_BASE + 312) },
	{ "send", (__SCMP_NR_BASE + 289) },
	{ "sendfile", (__SCMP_NR_BASE + 187) },
	{ "sendfile64", (__SCMP_NR_BASE + 239) },
	{ "sendmmsg", (__SCMP_NR_BASE + 374) },
	{ "sendmsg", (__SCMP_NR_BASE + 296) },
	{ "sendto", (__SCMP_NR_BASE + 290) },
	{ "set_mempolicy", (__SCMP_NR_BASE + 321) },
	{ "set_robust_list", (__SCMP_NR_BASE + 338) },
	{ "set_thread_area", __PNR_set_thread_area },
	{ "set_tid_address", (__SCMP_NR_BASE + 256) },
	{ "set_tls", (__SCMP_NR_BASE + (__SCMP_ARM_NR_BASE + 5)) },
	{ "setdomainname", (__SCMP_NR_BASE + 121) },
	{ "setfsgid", (__SCMP_NR_BASE + 139) },
	{ "setfsgid32", (__SCMP_NR_BASE + 216) },
	{ "setfsuid", (__SCMP_NR_BASE + 138) },
	{ "setfsuid32", (__SCMP_NR_BASE + 215) },
	{ "setgid", (__SCMP_NR_BASE + 46) },
	{ "setgid32", (__SCMP_NR_BASE + 214) },
	{ "setgroups", (__SCMP_NR_BASE + 81) },
	{ "setgroups32", (__SCMP_NR_BASE + 206) },
	{ "sethostname", (__SCMP_NR_BASE + 74) },
	{ "setitimer", (__SCMP_NR_BASE + 104) },
	{ "setns", (__SCMP_NR_BASE + 375) },
	{ "setpgid", (__SCMP_NR_BASE + 57) },
	{ "setpriority", (__SCMP_NR_BASE + 97) },
	{ "setregid", (__SCMP_NR_BASE + 71) },
	{ "setregid32", (__SCMP_NR_BASE + 204) },
	{ "setresgid", (__SCMP_NR_BASE + 170) },
	{ "setresgid32", (__SCMP_NR_BASE + 210) },
	{ "setresuid", (__SCMP_NR_BASE + 164) },
	{ "setresuid32", (__SCMP_NR_BASE + 208) },
	{ "setreuid", (__SCMP_NR_BASE + 70) },
	{ "setreuid32", (__SCMP_NR_BASE + 203) },
	{ "setrlimit", (__SCMP_NR_BASE + 75) },
	{ "setsid", (__SCMP_NR_BASE + 66) },
	{ "setsockopt", (__SCMP_NR_BASE + 294) },
	{ "settimeofday", (__SCMP_NR_BASE + 79) },
	{ "setuid", (__SCMP_NR_BASE + 23) },
	{ "setuid32", (__SCMP_NR_BASE + 213) },
	{ "setxattr", (__SCMP_NR_BASE + 226) },
	{ "sgetmask", __PNR_sgetmask },
	{ "shmat", (__SCMP_NR_BASE + 305) },
	{ "shmctl", (__SCMP_NR_BASE + 308) },
	{ "shmdt", (__SCMP_NR_BASE + 306) },
	{ "shmget", (__SCMP_NR_BASE + 307) },
	{ "shutdown", (__SCMP_NR_BASE + 293) },
	{ "sigaction", (__SCMP_NR_BASE + 67) },
	{ "sigaltstack", (__SCMP_NR_BASE + 186) },
	{ "signal", __PNR_signal },
	{ "signalfd", (__SCMP_NR_BASE + 349) },
	{ "signalfd4", (__SCMP_NR_BASE + 355) },
	{ "sigpending", (__SCMP_NR_BASE + 73) },
	{ "sigprocmask", (__SCMP_NR_BASE + 126) },
	{ "sigreturn", (__SCMP_NR_BASE + 119) },
	{ "sigsuspend", (__SCMP_NR_BASE + 72) },
	{ "socket", (__SCMP_NR_BASE + 281) },
	{ "socketcall", __PNR_socketcall },
	{ "socketpair", (__SCMP_NR_BASE + 288) },
	{ "splice", (__SCMP_NR_BASE + 340) },
	{ "spu_create", __PNR_spu_create },
	{ "spu_run", __PNR_spu_run },
	{ "ssetmask", __PNR_ssetmask },
	{ "stat", (__SCMP_NR_BASE + 106) },
	{ "stat64", (__SCMP_NR_BASE + 195) },
	{ "statfs", (__SCMP_NR_BASE + 99) },
	{ "statfs64", (__SCMP_NR_BASE + 266) },
	{ "stime", __PNR_stime },
	{ "stty", __PNR_stty },
	{ "subpage_prot", __PNR_subpage_prot },
	{ "swapcontext", __PNR_swapcontext },
	{ "swapoff", (__SCMP_NR_BASE + 115) },
	{ "swapon", (__SCMP_NR_BASE + 87) },
	{ "switch_endian", __PNR_switch_endian },
	{ "symlink", (__SCMP_NR_BASE + 83) },
	{ "symlinkat", (__SCMP_NR_BASE + 331) },
	{ "sync", (__SCMP_NR_BASE + 36) },
	{ "sync_file_range", __PNR_sync_file_range },
	{ "sync_file_range2", (__SCMP_NR_BASE + 341) },
	{ "syncfs", (__SCMP_NR_BASE + 373) },
	{ "syscall", (__PNR_syscall) },
	{ "sys_debug_setcontext", __PNR_sys_debug_setcontext },
	{ "sysfs", (__SCMP_NR_BASE + 135) },
	{ "sysinfo", (__SCMP_NR_BASE + 116) },
	{ "syslog", (__SCMP_NR_BASE + 103) },
	{ "sysmips", __PNR_sysmips },
	{ "tee", (__SCMP_NR_BASE + 342) },
	{ "tgkill", (__SCMP_NR_BASE + 268) },
	{ "time", __PNR_time },
	{ "timer_create", (__SCMP_NR_BASE + 257) },
	{ "timer_delete", (__SCMP_NR_BASE + 261) },
	{ "timer_getoverrun", (__SCMP_NR_BASE + 260) },
	{ "timer_gettime", (__SCMP_NR_BASE + 259) },
	{ "timer_settime", (__SCMP_NR_BASE + 258) },
	{ "timerfd", __PNR_timerfd },
	{ "timerfd_create", (__SCMP_NR_BASE + 350) },
	{ "timerfd_gettime", (__SCMP_NR_BASE + 354) },
	{ "timerfd_settime", (__SCMP_NR_BASE + 353) },
	{ "times", (__SCMP_NR_BASE + 43) },
	{ "tkill", (__SCMP_NR_BASE + 238) },
	{ "truncate", (__SCMP_NR_BASE + 92) },
	{ "truncate64", (__SCMP_NR_BASE + 193) },
	{ "tuxcall", __PNR_tuxcall },
	{ "ugetrlimit", (__SCMP_NR_BASE + 191) },
	{ "ulimit", __PNR_ulimit },
	{ "umask", (__SCMP_NR_BASE + 60) },
	{ "umount", __PNR_umount },
	{ "umount2", (__SCMP_NR_BASE + 52) },
	{ "uname", (__SCMP_NR_BASE + 122) },
	{ "unlink", (__SCMP_NR_BASE + 10) },
	{ "unlinkat", (__SCMP_NR_BASE + 328) },
	{ "unshare", (__SCMP_NR_BASE + 337) },
	{ "uselib", (__SCMP_NR_BASE + 86) },
	{ "userfaultfd", (__SCMP_NR_BASE + 388) },
	{ "usr26", (__SCMP_NR_BASE + (__SCMP_ARM_NR_BASE + 3)) },
	{ "usr32", (__SCMP_NR_BASE + (__SCMP_ARM_NR_BASE + 4)) },
	{ "ustat", (__SCMP_NR_BASE + 62) },
	{ "utime", __PNR_utime },
	{ "utimensat", (__SCMP_NR_BASE + 348) },
	{ "utimes", (__SCMP_NR_BASE + 269) },
	{ "vfork", (__SCMP_NR_BASE + 190) },
	{ "vhangup", (__SCMP_NR_BASE + 111) },
	{ "vm86", __PNR_vm86 },
	{ "vm86old", __PNR_vm86old },
	{ "vmsplice", (__SCMP_NR_BASE + 343) },
	{ "vserver", (__SCMP_NR_BASE + 313) },
	{ "wait4", (__SCMP_NR_BASE + 114) },
	{ "waitid", (__SCMP_NR_BASE + 280) },
	{ "waitpid", __PNR_waitpid },
	{ "write", (__SCMP_NR_BASE +  4) },
	{ "writev", (__SCMP_NR_BASE + 146) },
	{ NULL, __NR_SCMP_ERROR },
};

/**
 * Resolve a syscall name to a number
 * @param name the syscall name
 *
 * Resolve the given syscall name to the syscall number using the syscall table.
 * Returns the syscall number on success, including negative pseudo syscall
 * numbers; returns __NR_SCMP_ERROR on failure.
 *
 */
int arm_syscall_resolve_name(const char *name)
{
	unsigned int iter;
	const struct arch_syscall_def *table = arm_syscall_table;

	/* XXX - plenty of room for future improvement here */
	for (iter = 0; table[iter].name != NULL; iter++) {
		if (strcmp(name, table[iter].name) == 0)
			return table[iter].num;
	}

	return __NR_SCMP_ERROR;
}

/**
 * Resolve a syscall number to a name
 * @param num the syscall number
 *
 * Resolve the given syscall number to the syscall name using the syscall table.
 * Returns a pointer to the syscall name string on success, including pseudo
 * syscall names; returns NULL on failure.
 *
 */
const char *arm_syscall_resolve_num(int num)
{
	unsigned int iter;
	const struct arch_syscall_def *table = arm_syscall_table;

	/* XXX - plenty of room for future improvement here */
	for (iter = 0; table[iter].num != __NR_SCMP_ERROR; iter++) {
		if (num == table[iter].num)
			return table[iter].name;
	}

	return NULL;
}

/**
 * Iterate through the syscall table and return the syscall name
 * @param spot the offset into the syscall table
 *
 * Return the syscall name at position @spot or NULL on failure.  This function
 * should only ever be used internally by libseccomp.
 *
 */
const char *arm_syscall_iterate_name(unsigned int spot)
{
	/* XXX - no safety checks here */
	return arm_syscall_table[spot].name;
}
