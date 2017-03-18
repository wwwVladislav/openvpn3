//    OpenVPN -- An application to securely tunnel IP networks
//               over a single port, with support for SSL/TLS-based
//               session authentication and key exchange,
//               packet encryption, packet authentication, and
//               packet compression.
//
//    Copyright (C) 2012-2017 OpenVPN Technologies, Inc.
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License Version 3
//    as published by the Free Software Foundation.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program in the COPYING file.
//    If not, see <http://www.gnu.org/licenses/>.

#ifndef OPENVPN_COMMON_LOGROTATE_H
#define OPENVPN_COMMON_LOGROTATE_H

#include <stdio.h>     // for rename()

#include <openvpn/common/format.hpp>

namespace openvpn {
  inline void log_rotate(const std::string& fn, const int max_versions)
  {
    for (int i = max_versions - 1; i >= 0; --i)
      {
	std::string src;
	if (i)
	  src = fn + '.' + to_string(i);
	else
	  src = fn;
	std::string dest = fn + '.' + to_string(i+1);
	::rename(src.c_str(), dest.c_str());
      }
  }
}

#endif
