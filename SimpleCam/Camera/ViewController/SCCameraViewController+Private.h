//
//  SCCameraViewController+Private.h
//  SimpleCam
//
//  Created by Lyman Li on 2019/4/6.
//  Copyright © 2019年 Lyman Li. All rights reserved.
//

#import <GPUImage.h>
#import "SCCapturingButton.h"
#import "SCFilterBarView.h"

#import "SCCameraManager.h"
#import "SCFilterManager.h"

#import "SCCameraViewController.h"

@interface SCCameraViewController () <
    SCCapturingButtonDelegate,
    SCFilterBarViewDelegate,
    UIGestureRecognizerDelegate>

@property (nonatomic, strong) GPUImageView *cameraView;

@property (nonatomic, strong) SCCapturingButton *capturingButton;
@property (nonatomic, strong) SCFilterBarView *filterBarView;
@property (nonatomic, strong) UIButton *filterButton;

@property (nonatomic, strong) GPUImageOutput<GPUImageInput> *currentFilters;

@property (nonatomic, copy) NSArray<SCFilterMaterialModel *> *defaultFilterMaterials;

#pragma mark - UI

- (void)setupUI;

/**
 设置滤镜栏显示或隐藏
 
 @param hidden 显示或隐藏
 @param animated 是否有动画
 @param completion 完成回调
 */
- (void)setFilterBarViewHidden:(BOOL)hidden
                      animated:(BOOL)animated
                    completion:(void (^)(void))completion;

#pragma mark - Action

- (void)filterAction:(id)sender;

#pragma mark - Filter

- (void)setupFilters;

#pragma mark - TakePhoto

- (void)takePhoto;

@end