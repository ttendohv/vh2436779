/* 
 * File:   InventoryData.h
 * Author: Victoria
 *
 * Created on March 31, 2014, 3:40 PM
 */

#ifndef INVENTORYDATA_H
#define	INVENTORYDATA_H

int NAME=30,DATE=15;

struct Inventory{
    char    name[30],
            dateAdd[15];
    int     qty;
    float   wholesale,
            retail;
};

#endif	/* INVENTORYDATA_H */

