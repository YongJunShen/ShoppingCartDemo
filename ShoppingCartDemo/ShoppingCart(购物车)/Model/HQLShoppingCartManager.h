//
//  HQLShoppingCartManager.h
//  ProjectName
//
//  Created by Qilin Hu on 2020/4/30.
//  Copyright © 2020 Qilin Hu. All rights reserved.
//

#import <Foundation/Foundation.h>
@class HQLGoods;
@class HQLStore;

NS_ASSUME_NONNULL_BEGIN

/// 购物车商品管理类
@interface HQLShoppingCartManager : NSObject

@property (nonatomic, readonly) NSArray<HQLStore *> *stores;

/// 以下三个属性为结算商品时所需参数
@property (nonatomic, readonly, assign) NSInteger settleGoodsAmount;    // 结算商品数量
@property (nonatomic, readonly, assign) float settleTotalPrice;         // 结算商品合计价格
@property (nonatomic, assign, getter=isAllSelected) BOOL selectedState; // 是否全选
@property (nonatomic, assign, getter=isSettleButtonEnabled) BOOL settleButtonEnabled; // 是否禁用结算按钮

+ (instancetype)sharedManager;

- (void)loadShoppingCartGoods;

// 选中/取消选中某个 section 中的店铺
- (void)selectStoreInSection:(NSInteger)section selectedState:(BOOL)selectedState;

// 选中/取消选中某个 row 中的商品
- (void)selectGoodsAtIndexPath:(NSIndexPath *)indexPath selectedState:(BOOL)selectedState;

// 全选/取消全选
- (void)selectAllGoods:(BOOL)selectedState;

// 移除某个 row 中的商品
- (void)deleteGoodsAtIndexPath:(NSIndexPath *)indexPath;

// 修改商品购买数量
- (void)updateGoodsQuantity:(NSInteger)quantity atIndexPath:(NSIndexPath *)indexPath;

// 根据 section 返回 Store
- (HQLStore *)storeInSection:(NSInteger)section;

// 根据 indexPath 返回 Goods
- (HQLGoods *)goodsAtIndexPath:(NSIndexPath *)indexPath;

// 结算商品时，通过该方法返回选中商品
- (NSArray *)settleSelectedStores;

@end

NS_ASSUME_NONNULL_END
