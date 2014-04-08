/* 
 * File:   Budget.h
 * Author: Victoria
 *
 * Created on March 30, 2014, 8:09 PM
 */

#ifndef BUDGET_H
#define	BUDGET_H

//Monthly Budget
float HSNG    = 500.00,
      UTIL    = 150.00,
      HHEXP   = 65.00,
      TRANSP  = 50.00,
      FOOD    = 250.00,
      MEDCL   = 30.00,
      INSURC  = 100.00,
      ENTRMT  = 150.00,
      CLTHNG  = 75.00,
      MISC    = 50.00,
      TOTAL   = HSNG + UTIL + HHEXP + 
                TRANSP + FOOD + MEDCL + 
                INSURC + ENTRMT + CLTHNG + MISC;

struct MonthlyBudget{
    float housing,
          util,
          houseExp,
          transp,
          food,
          medic,
          insur,
          entertain,
          clothing,
          misc;
};

#endif	/* BUDGET_H */

