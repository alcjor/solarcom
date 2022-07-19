KPL/MK

File name: GFOccultationSearchEx1.tm

This meta-kernel is intended to support operation of SPICE
example programs. The kernels shown here should not be
assumed to contain adequate or correct versions of data
required by SPICE-based user applications.

In order for an application to use this meta-kernel, the
kernels referenced here must be present in the user's
current working directory.

The names and contents of the kernels referenced
by this meta-kernel are as follows:

  File name                        Contents
  ---------                        --------
  de430.bsp                        Planetary ephemeris
  pck00010.tpc                     Planet orientation and
                                   radii
  naif0012.tls                     Leapseconds

\begindata

   PATH_SYMBOLS    = ( 'HOME_KERNELS')

   PATH_VALUES     = (
                       '/home/jordi/SPICE/kernels'
                     )

  KERNELS_TO_LOAD = ( '$HOME_KERNELS/de430.bsp',
                      '$HOME_KERNELS/pck00010.tpc',
                      '$HOME_KERNELS/naif0012.tls'  )

\begintext