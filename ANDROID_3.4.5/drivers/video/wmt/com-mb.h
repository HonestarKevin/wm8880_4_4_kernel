/*++
 * WonderMedia Memory Block driver
 *
 * Copyright c 2010  WonderMedia  Technologies, Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * WonderMedia Technologies, Inc.
 * 10F, 529, Chung-Cheng Road, Hsin-Tien, Taipei 231, R.O.C
--*/

#ifndef COM_MB_H
/* To assert that only one occurrence is included */
#define COM_MB_H

/*-------------------- MODULE DEPENDENCY -------------------------------------*/

/*-------------------- EXPORTED PRIVATE CONSTANTS ----------------------------*/

/*------------------------------------------------------------------------------
   Macros below are used for driver in IOCTL
------------------------------------------------------------------------------*/
#define MB_IOC_MAGIC 'M'

/* O: physical address I: size */
#define MBIO_MALLOC _IOWR(MB_IOC_MAGIC, 0, unsigned long)
/* O: ummap size I: user address if map, physical address if not map */
#define MBIO_FREE _IOWR(MB_IOC_MAGIC, 1, unsigned long)
/* O: ummap size I: user address */
#define MBIO_UNMAP _IOWR(MB_IOC_MAGIC, 2, unsigned long)
/* O: mb size I: phys address */
#define MBIO_MBSIZE _IOWR(MB_IOC_MAGIC, 3, unsigned long)
/* O: max free mba size */
#define MBIO_MAX_AVAILABLE_SIZE _IOR(MB_IOC_MAGIC, 4, unsigned long)
/* advance use only */
/* I: user address */
#define MBIO_GET _IOW(MB_IOC_MAGIC, 5, unsigned long)
/* I: user address */
#define MBIO_PUT _IOW(MB_IOC_MAGIC, 6, unsigned long)
/* O: virt address I: user address */
#define MBIO_USER_TO_VIRT _IOWR(MB_IOC_MAGIC, 7, unsigned long)
/* O: phys address I: user address */
#define MBIO_USER_TO_PHYS _IOWR(MB_IOC_MAGIC, 8, unsigned long)
/* I: size */
#define MBIO_PREFETCH _IOW(MB_IOC_MAGIC, 9, unsigned long)
/* O: static mba size */
#define MBIO_STATIC_SIZE _IOR(MB_IOC_MAGIC, 10, unsigned long)
/* O: use counter I: physical address */
#define MBIO_MB_USER_COUNT _IOWR(MB_IOC_MAGIC, 11, unsigned long)
#define MBIO_FORCE_RESET _IO(MB_IOC_MAGIC, 12)
/* I: phys address */
#define MBIO_GET_BY_PHYS _IOW(MB_IOC_MAGIC, 13, unsigned long)
/* I: phys address */
#define MBIO_PUT_BY_PHYS _IOW(MB_IOC_MAGIC, 14, unsigned long)
/* I: user address */
#define MBIO_SYNC_CACHE _IOW(MB_IOC_MAGIC, 15, unsigned long)
/* O: mb driver version */
#define MBIO_GET_VERSION _IOR(MB_IOC_MAGIC, 16, unsigned long)
/* O: property of MB */
#define MBIO_SET_CACHABLE _IOW(MB_IOC_MAGIC, 17, unsigned long)
/* O: property of MB */
#define MBIO_CLR_CACHABLE _IOW(MB_IOC_MAGIC, 18, unsigned long)
/* I: phys address */
#define MBIO_STATIC_GET _IOW(MB_IOC_MAGIC, 19, unsigned long)
/* I: phys address */
#define MBIO_STATIC_PUT _IOW(MB_IOC_MAGIC, 20, unsigned long)
/* I: user address O: physical address */
#define MBIO_TEST_USER2PHYS _IOWR(MB_IOC_MAGIC, 100, unsigned long)
/* I: user address, size, prdt addr, and prdt size */
#define MBIO_TEST_USER2PRDT _IOWR(MB_IOC_MAGIC, 101, unsigned long)
/* I: user address, size, mmu addr, and mmu size O: mmu physical addr */
#define MBIO_TEST_USER2MMUT _IOWR(MB_IOC_MAGIC, 102, unsigned long)
/* I: user address, size, prdt addr, and prdt size */
#define MBIO_TEST_MB2PRDT _IOWR(MB_IOC_MAGIC, 103, unsigned long)
/* I: user address, size, mmu addr, and mmu size O: mmu physical addr */
#define MBIO_TEST_MB2MMUT _IOWR(MB_IOC_MAGIC, 104, unsigned long)

#endif /* ifndef COM_MB_H */

/*=== END com-mb.h ==========================================================*/

