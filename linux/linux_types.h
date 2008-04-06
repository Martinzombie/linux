# if !defined(LINUX_TYPES_H)
# define	LINUX_TYPES_H 1

# include	<features.h>


# include	<time.h>
# include	<sys/time.h>
# include	<sys/processor.h>
# include	<sys/systm.h>

# define	_LARGEFILE_SOURCE	1
# define	_FILE_OFFSET_BITS	64
# define 	__USE_LARGEFILE64 1

# include	<sys/types.h>
# include	<stdint.h>
# include	<unistd.h>
# include	<sys/wait.h>
# include	<zone.h>
/*# include	<sys/ucontext.h>*/
/*# include	<sys/reg.h>*/

// link.h
#define LM_ID_BASE              0x00

# define 	DEFAULTMUTEX 0

// fixme : objfs.h
# define	OBJFS_ROOT	"/system/object"

# define NGREG	19
# define	NPRGREG32 NGREG

#define P2ROUNDUP(x, align)             (-(-(x) & -(align)))

/* fix this */
extern int pread();
extern int pwrite();
# define	pread64	pread
# define	pwrite64 pwrite

#define FPS_TOP 0x00003800      /* top of stack pointer                 */

# define	REG_GS	0
# define	REG_FS	1
# define	REG_ES	2
# define	REG_DS	3
# define	EDI	4
# define	ESI	5
# define	EBP	6
# define	ESP	7
# define	EBX	8
# define	EDX	9
# define	ECX	10
# define	EAX	11
# define	TRAPNO	12
# define	ERR	13
# define	EIP	14
# define	REG_CS	15
# define	EFL	16
# define	REG_RFL	16	/* ?? */
# define	UESP	17
# define	REG_SS	18
# define DS 7
# define ES 8
# define FS 9
# define GS 10
# define CS  13
# define SS   16

/* x86-64 */
# define	REG_RDI	8
# define	REG_RSI	9
# define	REG_RBP	10
# define	REG_RBX	11
# define	REG_RDX	12
# define	REG_RAX	13
# define	REG_RCX	14
# define	REG_RSP	15
# define	REG_RIP	16
# define	REG_EFLAGS	17
# define	REG_ERR	22
# define	REG_TRAPNO 23

#define PAGESIZE        (sysconf(_SC_PAGESIZE)) /* All the above, for logical */

# if __KERNEL__
# include <sys/cpuvar_defs.h>
# include <asm/signal.h>
#define	USHRT_MAX	0xffff
#define	UINT16_MAX	0xffff
#define	INT32_MAX	0x7fffffff
#define	UINT32_MAX	0xffffffff
#define	INT64_MAX	0x7fffffffffffffff
#define	UINT64_MAX	0xffffffffffffffff
typedef int cred_t;
typedef struct	proc *proc_t;
typedef int *greg_t;
typedef struct __dev_info *dev_info_t;
typedef int 	processorid_t;
typedef int 	model_t;
typedef void	*vmem_t;
typedef int	cyclic_id_t;
typedef long	intptr_t;
typedef unsigned long uintptr_t;
typedef unsigned long long off64_t;
typedef void *taskq_t;
typedef void *kmem_cache_t;
typedef void *kthread_t;
typedef struct mutex kmutex_t;

#define	NBBY	8
#define	bcmp(a, b, c) memcmp(a, b, c)

#define	KM_SLEEP GFP_KERNEL
#define	KM_NOSLEEP GFP_ATOMIC

#define	CE_WARN	0
#define	CE_NOTE	1

#define	NCPU NR_CPUS

# endif
//typedef unsigned int *uintptr_t;
typedef short   o_dev_t;                /* old device type      */
//typedef int     processorid_t;
typedef unsigned short ushort_t;
typedef unsigned char uchar_t;
# if !defined(__KERNEL__)
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef int int32_t;
typedef char * caddr_t;
# endif
typedef unsigned int uint_t;
typedef unsigned int ulong_t;
//typedef unsigned long long uint64_t;
typedef unsigned long long u_longlong_t;
typedef long long longlong_t;
typedef long long offset_t;
typedef unsigned long long hrtime_t;
typedef unsigned long long rd_agent_t;
typedef unsigned long pc_t;
typedef ulong_t          Lmid_t;
typedef uint_t lwpid_t;
//typedef struct statvfs statvfs_t;
typedef u_longlong_t    core_content_t;
typedef unsigned long   psaddr_t;
typedef int	ctid_t;                 /* contract ID type     */
typedef int	zoneid_t;
typedef int	prgreg32_t;
typedef struct iovec iovec_t;
# define	ino64_t	ino_t
# define	blkcnt64_t blkcnt_t

# include	<sys/types32.h>

typedef union {
        long double     _q;
        uint32_t        _l[4];
} upad128_t;

#define SIG2STR_MAX     32

# define	B_TRUE	1
# define	B_FALSE	0

#define SI_SYSNAME              1       /* return name of operating system */
#define SI_RELEASE              3       /* return release of operating system */

#define SI_PLATFORM             513     /* return platform identifier */
#define SI_ISALIST              514     /* returnsupported isa list */

#define SYS_vfork       119
#define SYS_fork1       143
#define SYS_forkall     2
#define SYS_execve      59
#define SYS_statvfs     103
#define SYS_stat        18
#define SYS_stat64              215
#define	SYS_rename      134
#define SYS_link        9
#define SYS_unlink      10
#define SYS_sigaction   98
#define SYS_xstat       123
#define SYS_lxstat      124
#define SYS_fxstat      125
#define SYS_lstat       88
#define SYS_lstat64             216
#define SYS_fstat64             217
#define SYS_fstat       28
#define SYS_pset                207
#define SYS_munmap      117
#define SYS_open        5
#define SYS_creat       8
#define SYS_fstatvfs    104
#define SYS_zone                227
#define SYS_tasksys     70
#define SYS_waitsys     107
#define SYS_close       6
#define SYS_access      33
#define SYS_processor_bind      187
#define SYS_mmap        115
#define SYS_memcntl     131
#define SYS_meminfosys          SYS_lgrpsys
#define SYS_lgrpsys             180
#define SYS_exit        1
#define SYS_uadmin      55
#define SYS_ioctl       54
#define SYS_llseek              175
#define SYS_lseek       19
#define SYS_exec SYS_execve
#define SYS_fcntl       62
#define SYS_rctlsys     74
#define SYS_getitimer           157
#define SYS_setitimer           158
#define SYS_setrlimit64         220
#define SYS_getrlimit64         221
#define SYS_setrlimit   128
#define SYS_getrlimit   129
#define SYS_lwp_exit            160
#define SYS_door                201
#define SYS_getsockname         244
#define SYS_getpeername         243
#define SYS_getsockopt          245

/* fcntl.h */
#define F_ALLOCSP       10      /* Reserved */
#define F_FREESP        27      /* Free file space */
#define F_SHARE         40      /* Set a file share reservation */
#define F_UNSHARE       41      /* Remove a file share reservation */

/* modctl.h */
#define       MODGETPATH              6
#define       MODGETPATHLEN           14

/* time.h */
/*
 *      Definitions for commonly used resolutions.
 */
#define SEC             1
#define MILLISEC        1000
#define MICROSEC        1000000
#define NANOSEC         1000000000

/* zone.h */
#define GLOBAL_ZONEID   0
/*
# include	<sys/procfs.h>
struct pstatus *Pstatus();
*/

typedef struct timespec timestruc_t;

#if !defined(_LP64) && defined(__cplusplus)
typedef ulong_t major_t;        /* major part of device number */
typedef ulong_t minor_t;        /* minor part of device number */
#else
typedef uint_t major_t;
typedef uint_t minor_t;
#endif

typedef unsigned int mutex_t;

typedef struct flock64_32 {
        int16_t l_type;
        int16_t l_whence;
        off64_t l_start;
        off64_t l_len;          /* len == 0 means until end of file */
        int32_t l_sysid;
        pid32_t l_pid;
        int32_t l_pad[4];               /* reserve area */
} flock64_32_t;

/*
 * File share reservation type
 */
typedef struct fshare {
        short   f_access;
        short   f_deny;
        int     f_id;
} fshare_t;

/* time.h */
struct itimerval32 {
        struct  timeval32 it_interval;
        struct  timeval32 it_value;
};

/* sys/socketvar.h */
/*
 * Socket versions. Used by the socket library when calling _so_socket().
 */
#define SOV_STREAM      0       /* Not a socket - just a stream */
#define SOV_DEFAULT     1       /* Select based on so_default_version */
#define SOV_SOCKSTREAM  2       /* Socket plus streams operations */
#define SOV_SOCKBSD     3       /* Socket with no streams operations */
#define SOV_XPG4_2      4       /* Xnet socket */

/* mman.h */
#define _MAP_NEW        0x80000000      /* users should not need to use this */

#define MISYS_MEMINFO           0x0
struct memcntl_mha {
        uint_t          mha_cmd;        /* command(s) */
        uint_t          mha_flags;
        size_t          mha_pagesize;
};

struct memcntl_mha32 {
        uint_t          mha_cmd;        /* command(s) */
        uint_t          mha_flags;
        size32_t        mha_pagesize;
};
#define MC_HAT_ADVISE   7               /* advise hat map size */
typedef struct meminfo {
        const uint64_t *mi_inaddr;      /* array of input addresses */
        const uint_t *mi_info_req;      /* array of types of info requested */
        uint64_t *mi_outdata;           /* array of results are placed */
        uint_t *mi_validity;            /* array of bitwise result codes */
        int mi_info_count;              /* number of pieces of info requested */
} meminfo_t;
typedef struct meminfo32 {
        caddr32_t mi_inaddr;    /* array of input addresses */
        caddr32_t mi_info_req;  /* array of types of information requested */
        caddr32_t mi_outdata;   /* array of results are placed */
        caddr32_t mi_validity;  /* array of bitwise result codes */
        int32_t mi_info_count;  /* number of pieces of information requested */
} meminfo32_t;

# endif
