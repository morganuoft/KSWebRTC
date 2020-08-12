//
//  KSLocalCell.h
//  KSWebRTC
//
//  Created by saeipi on 2020/8/12.
//  Copyright © 2020 saeipi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KSLocalView.h"
#import "KSMediaConnection.h"

@interface KSLocalCell : UICollectionViewCell

@property(nonatomic,weak)KSMediaConnection *connection;

@end
