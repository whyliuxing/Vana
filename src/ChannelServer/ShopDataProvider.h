/*
Copyright (C) 2008-2009 Vana Development Team

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#ifndef SHOPDATA_H
#define SHOPDATA_H

#include "Types.h"
#include <boost/tr1/unordered_map.hpp>
#include <map>
#include <vector>

using std::map;
using std::tr1::unordered_map;
using std::vector;

class Player;

struct ShopInfo {
	int32_t npc;
	vector<int32_t> items;
	unordered_map<int32_t, int32_t> prices;
	int8_t rechargetier;
};

class ShopDataProvider {
public:
	static ShopDataProvider * Instance() {
		if (singleton == 0)
			singleton = new ShopDataProvider();
		return singleton;
	}
	void loadData();
	bool showShop(Player *player, int32_t id);
	int32_t getPrice(int32_t shopid, int32_t itemid);
private:
	ShopDataProvider() {}
	static ShopDataProvider *singleton;

	unordered_map<int32_t, ShopInfo> shops;
	unordered_map<int8_t, map<int32_t, double> > rechargecosts;
};

#endif
