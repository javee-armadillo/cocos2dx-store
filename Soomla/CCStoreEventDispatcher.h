
#ifndef __CCStoreEventDispatcher_H_
#define __CCStoreEventDispatcher_H_

#include "cocos2d.h"
#include "CCVirtualGood.h"
#include "CCVirtualCurrency.h"
#include "CCPurchasableVirtualItem.h"
#include "CCEquippableVG.h"
#include "CCUpgradeVG.h"

namespace soomla {
    class CCStoreEventDispatcher: public cocos2d::Ref {
    public:
        /**
        This class is singleton, access it with this function.
        */
        static CCStoreEventDispatcher *getInstance();

        bool init();

        virtual void onBillingNotSupported();

        virtual void onBillingSupported();

        virtual void onCurrencyBalanceChanged(CCVirtualCurrency *virtualCurrency, int balance, int amountAdded);

        virtual void onGoodBalanceChanged(CCVirtualGood *virtualGood, int balance, int amountAdded);

        virtual void onGoodEquipped(CCEquippableVG *equippableVG);

        virtual void onGoodUnEquipped(CCEquippableVG *equippableVG);

        virtual void onGoodUpgrade(CCVirtualGood *virtualGood, CCUpgradeVG *upgradeVG);

        virtual void onItemPurchased(CCPurchasableVirtualItem *purchasableVirtualItem, cocos2d::__String *payload);
        
        virtual void onItemPurchased(CCPurchasableVirtualItem *purchasableVirtualItem, cocos2d::__String *payload, bool alsoPush);

        virtual void onItemPurchaseStarted(CCPurchasableVirtualItem *purchasableVirtualItem);
        
        virtual void onItemPurchaseStarted(CCPurchasableVirtualItem *purchasableVirtualItem, bool alsoPush);

        virtual void onMarketPurchaseCancelled(CCPurchasableVirtualItem *purchasableVirtualItem);

        virtual void onMarketPurchase(CCPurchasableVirtualItem *purchasableVirtualItem, cocos2d::__String *token, cocos2d::__String *payload);

        virtual void onMarketPurchaseStarted(CCPurchasableVirtualItem *purchasableVirtualItem);

        virtual void onMarketPurchaseVerification(CCPurchasableVirtualItem *purchasableVirtualItem);

        virtual void onRestoreTransactionsFinished(bool success);

        virtual void onRestoreTransactionsStarted();

        virtual void onUnexpectedErrorInStore(cocos2d::__String *errorMessage);
        
        virtual void onUnexpectedErrorInStore(cocos2d::__String *errorMessage, bool alsoPush);

        virtual void onSoomlaStoreInitialized();
        
        virtual void onSoomlaStoreInitialized(bool alsoPush);

        virtual void onMarketItemsRefreshed(cocos2d::__Array *marketItems);

/** Android only events*/
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

        virtual void onMarketRefund(CCPurchasableVirtualItem *purchasableVirtualItem);

        virtual void onIabServiceStarted();

        virtual void onIabServiceStopped();
#endif

        virtual void onMarketItemsRefreshStarted();
        
        virtual void onMarketItemsRefreshFailed(cocos2d::__String *errorMessage);
    };
}


#endif //__CCStoreEventDispatcher_H_
