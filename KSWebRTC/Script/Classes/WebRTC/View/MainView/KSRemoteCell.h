//
//  KSRemoteCell.h
//  KSWebRTC
//
//  Created by saeipi on 2020/8/12.
//  Copyright © 2020 saeipi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KSMediaConnection.h"

@interface KSRemoteCell : UICollectionViewCell

@property(nonatomic,weak)KSMediaConnection *connection;

@end
