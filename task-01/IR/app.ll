; ModuleID = 'app.c'
source_filename = "app.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@sin_table_precise = internal unnamed_addr constant [361 x i32] [i32 0, i32 286, i32 572, i32 858, i32 1144, i32 1430, i32 1716, i32 2001, i32 2287, i32 2573, i32 2859, i32 3144, i32 3430, i32 3715, i32 4001, i32 4286, i32 4571, i32 4857, i32 5142, i32 5427, i32 5712, i32 5997, i32 6281, i32 6566, i32 6850, i32 7135, i32 7419, i32 7703, i32 7987, i32 8270, i32 8554, i32 8837, i32 9121, i32 9404, i32 9687, i32 9969, i32 10252, i32 10534, i32 10816, i32 11098, i32 11380, i32 11662, i32 11943, i32 12224, i32 12505, i32 12785, i32 13066, i32 13346, i32 13625, i32 13905, i32 14184, i32 14463, i32 14742, i32 15021, i32 15299, i32 15577, i32 15854, i32 16132, i32 16409, i32 16685, i32 16962, i32 17238, i32 17513, i32 17789, i32 18064, i32 18339, i32 18613, i32 18887, i32 19161, i32 19434, i32 19707, i32 19979, i32 20251, i32 20523, i32 20795, i32 21066, i32 21336, i32 21606, i32 21876, i32 22145, i32 22414, i32 22683, i32 22951, i32 23218, i32 23486, i32 23752, i32 24019, i32 24284, i32 24550, i32 24815, i32 25079, i32 25343, i32 25607, i32 25870, i32 26132, i32 26394, i32 26655, i32 26916, i32 27177, i32 27437, i32 27696, i32 27955, i32 28214, i32 28471, i32 28729, i32 28985, i32 29242, i32 29497, i32 29752, i32 30007, i32 30261, i32 30514, i32 30767, i32 31019, i32 31271, i32 31522, i32 31772, i32 32022, i32 32271, i32 32520, i32 32767, i32 33015, i32 33262, i32 33508, i32 33753, i32 33998, i32 34242, i32 34485, i32 34728, i32 34970, i32 35212, i32 35453, i32 35693, i32 35932, i32 36171, i32 36409, i32 36647, i32 36883, i32 37119, i32 37355, i32 37589, i32 37823, i32 38056, i32 38289, i32 38521, i32 38751, i32 38982, i32 39211, i32 39440, i32 39668, i32 39895, i32 40122, i32 40347, i32 40572, i32 40796, i32 41020, i32 41243, i32 41464, i32 41685, i32 41906, i32 42125, i32 42344, i32 42562, i32 42779, i32 42995, i32 43210, i32 43425, i32 43639, i32 43851, i32 44064, i32 44275, i32 44485, i32 44695, i32 44903, i32 45111, i32 45318, i32 45524, i32 45730, i32 45934, i32 46138, i32 46340, i32 46542, i32 46743, i32 46943, i32 47142, i32 47340, i32 47537, i32 47734, i32 47929, i32 48124, i32 48317, i32 48510, i32 48702, i32 48893, i32 49083, i32 49272, i32 49460, i32 49647, i32 49833, i32 50018, i32 50203, i32 50386, i32 50568, i32 50750, i32 50930, i32 51110, i32 51288, i32 51466, i32 51642, i32 51818, i32 51992, i32 52166, i32 52339, i32 52510, i32 52681, i32 52850, i32 53019, i32 53187, i32 53353, i32 53519, i32 53683, i32 53847, i32 54009, i32 54171, i32 54331, i32 54490, i32 54649, i32 54806, i32 54962, i32 55117, i32 55272, i32 55425, i32 55577, i32 55728, i32 55878, i32 56027, i32 56174, i32 56321, i32 56467, i32 56611, i32 56755, i32 56897, i32 57039, i32 57179, i32 57318, i32 57456, i32 57593, i32 57729, i32 57864, i32 57998, i32 58130, i32 58262, i32 58392, i32 58521, i32 58650, i32 58777, i32 58902, i32 59027, i32 59151, i32 59273, i32 59395, i32 59515, i32 59634, i32 59752, i32 59869, i32 59985, i32 60100, i32 60213, i32 60325, i32 60436, i32 60546, i32 60655, i32 60763, i32 60870, i32 60975, i32 61079, i32 61182, i32 61284, i32 61385, i32 61484, i32 61583, i32 61680, i32 61776, i32 61871, i32 61965, i32 62057, i32 62148, i32 62239, i32 62327, i32 62415, i32 62502, i32 62587, i32 62671, i32 62754, i32 62836, i32 62917, i32 62996, i32 63075, i32 63152, i32 63227, i32 63302, i32 63375, i32 63448, i32 63519, i32 63588, i32 63657, i32 63724, i32 63790, i32 63855, i32 63919, i32 63982, i32 64043, i32 64103, i32 64162, i32 64219, i32 64276, i32 64331, i32 64385, i32 64438, i32 64489, i32 64539, i32 64588, i32 64636, i32 64683, i32 64728, i32 64772, i32 64815, i32 64857, i32 64897, i32 64936, i32 64974, i32 65011, i32 65047, i32 65081, i32 65114, i32 65145, i32 65176, i32 65205, i32 65233, i32 65260, i32 65286, i32 65310, i32 65333, i32 65355, i32 65375, i32 65395, i32 65413, i32 65430, i32 65445, i32 65460, i32 65473, i32 65484, i32 65495, i32 65504, i32 65513, i32 65519, i32 65525, i32 65529, i32 65533, i32 65534, i32 65535], align 16

; Function Attrs: nounwind uwtable
define dso_local i32 @calculate_ray_length() local_unnamed_addr #0 {
  %1 = call i32 @sim_sqrt(i32 noundef 640000) #5
  ret i32 %1
}

declare i32 @sim_sqrt(i32 noundef) local_unnamed_addr #1

; Function Attrs: nounwind uwtable
define dso_local void @draw_circle(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3) local_unnamed_addr #0 {
  %5 = shl i32 %2, 1
  %6 = icmp sgt i32 %2, 0
  br i1 %6, label %7, label %16

7:                                                ; preds = %4
  %8 = mul nsw i32 %2, %2
  %9 = call i32 @llvm.smax.i32(i32 %5, i32 1)
  %10 = call i32 @llvm.smax.i32(i32 %5, i32 1)
  br label %11

11:                                               ; preds = %7, %17
  %12 = phi i32 [ 0, %7 ], [ %18, %17 ]
  %13 = sub nsw i32 %2, %12
  %14 = mul nsw i32 %13, %13
  %15 = add nsw i32 %13, %0
  br label %20

16:                                               ; preds = %17, %4
  ret void

17:                                               ; preds = %28
  %18 = add nuw nsw i32 %12, 1
  %19 = icmp eq i32 %18, %10
  br i1 %19, label %16, label %11, !llvm.loop !5

20:                                               ; preds = %11, %28
  %21 = phi i32 [ 0, %11 ], [ %29, %28 ]
  %22 = sub nsw i32 %2, %21
  %23 = mul nsw i32 %22, %22
  %24 = add nuw nsw i32 %23, %14
  %25 = icmp ugt i32 %24, %8
  br i1 %25, label %28, label %26

26:                                               ; preds = %20
  %27 = add nsw i32 %22, %1
  call void @sim_put_pixel(i32 noundef %15, i32 noundef %27, i32 noundef %3) #5
  br label %28

28:                                               ; preds = %26, %20
  %29 = add nuw nsw i32 %21, 1
  %30 = icmp eq i32 %29, %9
  br i1 %30, label %17, label %20, !llvm.loop !8
}

declare void @sim_put_pixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #1

; Function Attrs: nofree norecurse nosync nounwind readnone uwtable
define dso_local i32 @get_sin_precise(i32 noundef %0) local_unnamed_addr #2 {
  %2 = call i32 @llvm.smax.i32(i32 %0, i32 0)
  %3 = sub i32 %2, %0
  %4 = icmp ne i32 %3, 0
  %5 = zext i1 %4 to i32
  %6 = sub i32 %3, %5
  %7 = udiv i32 %6, 1440
  %8 = add nuw nsw i32 %7, %5
  %9 = mul i32 %8, 1440
  %10 = add i32 %9, %0
  %11 = icmp sgt i32 %10, 1439
  %12 = srem i32 %10, 1440
  %13 = select i1 %11, i32 %12, i32 %10
  %14 = icmp slt i32 %13, 361
  br i1 %14, label %15, label %19

15:                                               ; preds = %1
  %16 = sext i32 %13 to i64
  %17 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %16
  %18 = load i32, i32* %17, align 4, !tbaa !9
  br label %40

19:                                               ; preds = %1
  %20 = icmp slt i32 %13, 721
  br i1 %20, label %21, label %26

21:                                               ; preds = %19
  %22 = sub nsw i32 720, %13
  %23 = zext i32 %22 to i64
  %24 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %23
  %25 = load i32, i32* %24, align 4, !tbaa !9
  br label %40

26:                                               ; preds = %19
  %27 = icmp slt i32 %13, 1081
  br i1 %27, label %28, label %34

28:                                               ; preds = %26
  %29 = add nsw i32 %13, -720
  %30 = zext i32 %29 to i64
  %31 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %30
  %32 = load i32, i32* %31, align 4, !tbaa !9
  %33 = sub nsw i32 0, %32
  br label %40

34:                                               ; preds = %26
  %35 = sub nsw i32 1440, %13
  %36 = zext i32 %35 to i64
  %37 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %36
  %38 = load i32, i32* %37, align 4, !tbaa !9
  %39 = sub nsw i32 0, %38
  br label %40

40:                                               ; preds = %34, %28, %21, %15
  %41 = phi i32 [ %18, %15 ], [ %25, %21 ], [ %33, %28 ], [ %39, %34 ]
  ret i32 %41
}

; Function Attrs: mustprogress nofree nosync nounwind readnone uwtable willreturn
define dso_local i32 @get_cos_precise(i32 noundef %0) local_unnamed_addr #3 {
  %2 = add nsw i32 %0, 360
  %3 = call i32 @llvm.smax.i32(i32 %2, i32 0) #5
  %4 = sub i32 %3, %2
  %5 = icmp ne i32 %4, 0
  %6 = zext i1 %5 to i32
  %7 = sub i32 %4, %6
  %8 = udiv i32 %7, 1440
  %9 = add nuw nsw i32 %8, %6
  %10 = mul i32 %9, 1440
  %11 = add i32 %10, %2
  %12 = icmp sgt i32 %11, 1439
  %13 = srem i32 %11, 1440
  %14 = select i1 %12, i32 %13, i32 %11
  %15 = icmp slt i32 %14, 361
  br i1 %15, label %16, label %20

16:                                               ; preds = %1
  %17 = sext i32 %14 to i64
  %18 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %17
  %19 = load i32, i32* %18, align 4, !tbaa !9
  br label %41

20:                                               ; preds = %1
  %21 = icmp slt i32 %14, 721
  br i1 %21, label %22, label %27

22:                                               ; preds = %20
  %23 = sub nsw i32 720, %14
  %24 = zext i32 %23 to i64
  %25 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %24
  %26 = load i32, i32* %25, align 4, !tbaa !9
  br label %41

27:                                               ; preds = %20
  %28 = icmp slt i32 %14, 1081
  br i1 %28, label %29, label %35

29:                                               ; preds = %27
  %30 = add nsw i32 %14, -720
  %31 = zext i32 %30 to i64
  %32 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %31
  %33 = load i32, i32* %32, align 4, !tbaa !9
  %34 = sub nsw i32 0, %33
  br label %41

35:                                               ; preds = %27
  %36 = sub nsw i32 1440, %14
  %37 = zext i32 %36 to i64
  %38 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %37
  %39 = load i32, i32* %38, align 4, !tbaa !9
  %40 = sub nsw i32 0, %39
  br label %41

41:                                               ; preds = %16, %22, %29, %35
  %42 = phi i32 [ %19, %16 ], [ %26, %22 ], [ %34, %29 ], [ %40, %35 ]
  ret i32 %42
}

; Function Attrs: nounwind uwtable
define dso_local i32 @has_interception(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6) local_unnamed_addr #0 {
  %8 = sub nsw i32 %3, %1
  %9 = mul nsw i32 %8, %4
  %10 = sub nsw i32 %2, %0
  %11 = mul nsw i32 %2, %1
  %12 = mul i32 %3, %0
  %13 = mul i32 %10, %5
  %14 = add i32 %13, %12
  %15 = add i32 %9, %11
  %16 = sub i32 %15, %14
  %17 = call i32 @llvm.abs.i32(i32 %16, i1 true)
  %18 = mul nsw i32 %8, %8
  %19 = mul nsw i32 %10, %10
  %20 = add nuw nsw i32 %18, %19
  %21 = call i32 @sim_sqrt(i32 noundef %20) #5
  %22 = sdiv i32 %17, %21
  %23 = icmp sgt i32 %22, %6
  br i1 %23, label %35, label %24

24:                                               ; preds = %7
  %25 = sub nsw i32 %0, %4
  %26 = sub nsw i32 %0, %2
  %27 = mul nsw i32 %25, %26
  %28 = icmp sgt i32 %27, 0
  br i1 %28, label %35, label %29

29:                                               ; preds = %24
  %30 = sub nsw i32 %1, %5
  %31 = sub nsw i32 %1, %3
  %32 = mul nsw i32 %30, %31
  %33 = icmp sgt i32 %32, 0
  %34 = zext i1 %33 to i32
  br label %35

35:                                               ; preds = %29, %24, %7
  %36 = phi i32 [ 0, %7 ], [ 1, %24 ], [ %34, %29 ]
  ret i32 %36
}

; Function Attrs: nounwind uwtable
define dso_local void @calc_interception(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32* nocapture noundef writeonly %7, i32* nocapture noundef writeonly %8) local_unnamed_addr #0 {
  %10 = sub nsw i32 %4, %0
  %11 = mul nsw i32 %10, %10
  %12 = sub nsw i32 %5, %1
  %13 = mul nsw i32 %12, %12
  %14 = add nuw nsw i32 %13, %11
  %15 = call i32 @sim_sqrt(i32 noundef %14) #5
  %16 = sub nsw i32 %15, %6
  %17 = sub nsw i32 %2, %0
  %18 = sub nsw i32 %3, %1
  %19 = mul nsw i32 %17, %17
  %20 = mul nsw i32 %18, %18
  %21 = add nuw nsw i32 %20, %19
  %22 = call i32 @sim_sqrt(i32 noundef %21) #5
  %23 = icmp slt i32 %6, 0
  br i1 %23, label %48, label %24

24:                                               ; preds = %9
  %25 = sub i32 %0, %4
  %26 = sub i32 %1, %5
  %27 = mul nsw i32 %6, %6
  br label %28

28:                                               ; preds = %24, %28
  %29 = phi i32 [ %16, %24 ], [ %46, %28 ]
  %30 = phi i32 [ %15, %24 ], [ %45, %28 ]
  %31 = add nsw i32 %29, %30
  %32 = sdiv i32 %31, 2
  %33 = mul nsw i32 %32, %17
  %34 = sdiv i32 %33, %22
  %35 = mul nsw i32 %32, %18
  %36 = sdiv i32 %35, %22
  %37 = add i32 %25, %34
  %38 = mul nsw i32 %37, %37
  %39 = add i32 %26, %36
  %40 = mul nsw i32 %39, %39
  %41 = add nuw nsw i32 %40, %38
  %42 = icmp ugt i32 %41, %27
  %43 = add nsw i32 %32, -1
  %44 = add nsw i32 %32, 1
  %45 = select i1 %42, i32 %30, i32 %43
  %46 = select i1 %42, i32 %44, i32 %29
  %47 = icmp sgt i32 %46, %45
  br i1 %47, label %48, label %28, !llvm.loop !13

48:                                               ; preds = %28, %9
  %49 = phi i32 [ %16, %9 ], [ %46, %28 ]
  %50 = mul nsw i32 %49, %17
  %51 = sdiv i32 %50, %22
  %52 = add nsw i32 %51, %0
  store i32 %52, i32* %7, align 4, !tbaa !9
  %53 = mul nsw i32 %49, %18
  %54 = sdiv i32 %53, %22
  %55 = add nsw i32 %54, %1
  store i32 %55, i32* %8, align 4, !tbaa !9
  ret void
}

; Function Attrs: nounwind uwtable
define dso_local void @draw_rays(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5) local_unnamed_addr #0 {
  %7 = sdiv i32 1440, %3
  %8 = icmp sgt i32 %3, 0
  br i1 %8, label %9, label %21

9:                                                ; preds = %6
  %10 = sub i32 320, %0
  %11 = sub i32 240, %1
  %12 = sub nsw i32 320, %0
  %13 = mul nsw i32 %12, %12
  %14 = sub nsw i32 240, %1
  %15 = mul nsw i32 %14, %14
  %16 = add nuw nsw i32 %15, %13
  %17 = icmp slt i32 %2, 0
  %18 = add i32 %0, -320
  %19 = add i32 %1, -240
  %20 = mul nsw i32 %2, %2
  br label %22

21:                                               ; preds = %169, %6
  ret void

22:                                               ; preds = %9, %169
  %23 = phi i32 [ 0, %9 ], [ %170, %169 ]
  %24 = mul nsw i32 %23, %7
  %25 = call i32 @llvm.smax.i32(i32 %24, i32 0) #5
  %26 = sub i32 %25, %24
  %27 = icmp ne i32 %26, 0
  %28 = zext i1 %27 to i32
  %29 = sub i32 %26, %28
  %30 = udiv i32 %29, 1440
  %31 = add nuw nsw i32 %30, %28
  %32 = mul i32 %31, 1440
  %33 = add i32 %32, %24
  %34 = icmp sgt i32 %33, 1439
  %35 = srem i32 %33, 1440
  %36 = select i1 %34, i32 %35, i32 %33
  %37 = icmp slt i32 %36, 361
  br i1 %37, label %38, label %42

38:                                               ; preds = %22
  %39 = sext i32 %36 to i64
  %40 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %39
  %41 = load i32, i32* %40, align 4, !tbaa !9
  br label %63

42:                                               ; preds = %22
  %43 = icmp slt i32 %36, 721
  br i1 %43, label %44, label %49

44:                                               ; preds = %42
  %45 = sub nsw i32 720, %36
  %46 = zext i32 %45 to i64
  %47 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %46
  %48 = load i32, i32* %47, align 4, !tbaa !9
  br label %63

49:                                               ; preds = %42
  %50 = icmp slt i32 %36, 1081
  br i1 %50, label %51, label %57

51:                                               ; preds = %49
  %52 = add nsw i32 %36, -720
  %53 = zext i32 %52 to i64
  %54 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %53
  %55 = load i32, i32* %54, align 4, !tbaa !9
  %56 = sub nsw i32 0, %55
  br label %63

57:                                               ; preds = %49
  %58 = sub nsw i32 1440, %36
  %59 = zext i32 %58 to i64
  %60 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %59
  %61 = load i32, i32* %60, align 4, !tbaa !9
  %62 = sub nsw i32 0, %61
  br label %63

63:                                               ; preds = %38, %44, %51, %57
  %64 = phi i32 [ %41, %38 ], [ %48, %44 ], [ %56, %51 ], [ %62, %57 ]
  %65 = add nsw i32 %24, 360
  %66 = call i32 @llvm.smax.i32(i32 %65, i32 0) #5
  %67 = sub i32 %66, %65
  %68 = icmp ne i32 %67, 0
  %69 = zext i1 %68 to i32
  %70 = sub i32 %67, %69
  %71 = udiv i32 %70, 1440
  %72 = add nuw nsw i32 %71, %69
  %73 = mul i32 %72, 1440
  %74 = add i32 %73, %65
  %75 = icmp sgt i32 %74, 1439
  %76 = srem i32 %74, 1440
  %77 = select i1 %75, i32 %76, i32 %74
  %78 = icmp slt i32 %77, 361
  br i1 %78, label %79, label %83

79:                                               ; preds = %63
  %80 = sext i32 %77 to i64
  %81 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %80
  %82 = load i32, i32* %81, align 4, !tbaa !9
  br label %104

83:                                               ; preds = %63
  %84 = icmp slt i32 %77, 721
  br i1 %84, label %85, label %90

85:                                               ; preds = %83
  %86 = sub nsw i32 720, %77
  %87 = zext i32 %86 to i64
  %88 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %87
  %89 = load i32, i32* %88, align 4, !tbaa !9
  br label %104

90:                                               ; preds = %83
  %91 = icmp slt i32 %77, 1081
  br i1 %91, label %92, label %98

92:                                               ; preds = %90
  %93 = add nsw i32 %77, -720
  %94 = zext i32 %93 to i64
  %95 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %94
  %96 = load i32, i32* %95, align 4, !tbaa !9
  %97 = sub nsw i32 0, %96
  br label %104

98:                                               ; preds = %90
  %99 = sub nsw i32 1440, %77
  %100 = zext i32 %99 to i64
  %101 = getelementptr inbounds [361 x i32], [361 x i32]* @sin_table_precise, i64 0, i64 %100
  %102 = load i32, i32* %101, align 4, !tbaa !9
  %103 = sub nsw i32 0, %102
  br label %104

104:                                              ; preds = %79, %85, %92, %98
  %105 = phi i32 [ %82, %79 ], [ %89, %85 ], [ %97, %92 ], [ %103, %98 ]
  %106 = mul nsw i32 %105, %4
  %107 = sdiv i32 %106, 65535
  %108 = add nsw i32 %107, %0
  %109 = mul nsw i32 %64, %4
  %110 = sdiv i32 %109, 65535
  %111 = add nsw i32 %110, %1
  %112 = mul nsw i32 %110, 320
  %113 = mul nsw i32 %108, %1
  %114 = mul i32 %111, %0
  %115 = mul nsw i32 %107, -240
  %116 = sub i32 %112, %114
  %117 = add i32 %116, %115
  %118 = add i32 %117, %113
  %119 = call i32 @llvm.abs.i32(i32 %118, i1 true) #5
  %120 = mul nsw i32 %110, %110
  %121 = mul nsw i32 %107, %107
  %122 = add nuw nsw i32 %121, %120
  %123 = call i32 @sim_sqrt(i32 noundef %122) #5
  %124 = sdiv i32 %119, %123
  %125 = icmp sgt i32 %124, %2
  br i1 %125, label %133, label %126

126:                                              ; preds = %104
  %127 = mul i32 %107, %10
  %128 = icmp sgt i32 %127, 0
  br i1 %128, label %133, label %129

129:                                              ; preds = %126
  %130 = mul i32 %110, %11
  %131 = icmp sgt i32 %130, 0
  %132 = zext i1 %131 to i32
  br label %133

133:                                              ; preds = %104, %126, %129
  %134 = phi i32 [ 0, %104 ], [ 1, %126 ], [ %132, %129 ]
  %135 = icmp eq i32 %134, 0
  br i1 %135, label %136, label %137

136:                                              ; preds = %133
  call void @sim_draw_line(i32 noundef %0, i32 noundef %1, i32 noundef %108, i32 noundef %111, i32 noundef %5) #5
  br label %169

137:                                              ; preds = %133
  %138 = call i32 @sim_sqrt(i32 noundef %16) #5
  %139 = sub nsw i32 %138, %2
  %140 = call i32 @sim_sqrt(i32 noundef %122) #5
  br i1 %17, label %161, label %141

141:                                              ; preds = %137, %141
  %142 = phi i32 [ %159, %141 ], [ %139, %137 ]
  %143 = phi i32 [ %158, %141 ], [ %138, %137 ]
  %144 = add nsw i32 %143, %142
  %145 = sdiv i32 %144, 2
  %146 = mul nsw i32 %145, %107
  %147 = sdiv i32 %146, %140
  %148 = mul nsw i32 %145, %110
  %149 = sdiv i32 %148, %140
  %150 = add i32 %18, %147
  %151 = mul nsw i32 %150, %150
  %152 = add i32 %19, %149
  %153 = mul nsw i32 %152, %152
  %154 = add nuw nsw i32 %153, %151
  %155 = icmp ugt i32 %154, %20
  %156 = add nsw i32 %145, -1
  %157 = add nsw i32 %145, 1
  %158 = select i1 %155, i32 %143, i32 %156
  %159 = select i1 %155, i32 %157, i32 %142
  %160 = icmp sgt i32 %159, %158
  br i1 %160, label %161, label %141, !llvm.loop !13

161:                                              ; preds = %141, %137
  %162 = phi i32 [ %139, %137 ], [ %159, %141 ]
  %163 = mul nsw i32 %162, %107
  %164 = sdiv i32 %163, %140
  %165 = add nsw i32 %164, %0
  %166 = mul nsw i32 %162, %110
  %167 = sdiv i32 %166, %140
  %168 = add nsw i32 %167, %1
  call void @sim_draw_line(i32 noundef %0, i32 noundef %1, i32 noundef %165, i32 noundef %168, i32 noundef %5) #5
  br label %169

169:                                              ; preds = %161, %136
  %170 = add nuw nsw i32 %23, 1
  %171 = icmp eq i32 %170, %3
  br i1 %171, label %21, label %22, !llvm.loop !14
}

declare void @sim_draw_line(i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #1

; Function Attrs: nounwind uwtable
define dso_local void @app() local_unnamed_addr #0 {
  %1 = call i32 @sim_sqrt(i32 noundef 640000) #5
  %2 = call i32 @sim_should_quit() #5
  %3 = icmp eq i32 %2, 0
  br i1 %3, label %5, label %4

4:                                                ; preds = %61, %0
  ret void

5:                                                ; preds = %0, %61
  %6 = phi i32 [ %64, %61 ], [ 0, %0 ]
  call void @sim_flush() #5
  %7 = icmp slt i32 %6, 580
  br i1 %7, label %8, label %10

8:                                                ; preds = %5
  %9 = add nsw i32 %6, 30
  br label %20

10:                                               ; preds = %5
  %11 = icmp slt i32 %6, 1000
  br i1 %11, label %12, label %14

12:                                               ; preds = %10
  %13 = add nsw i32 %6, -550
  br label %20

14:                                               ; preds = %10
  %15 = icmp slt i32 %6, 1580
  br i1 %15, label %16, label %18

16:                                               ; preds = %14
  %17 = sub i32 1610, %6
  br label %20

18:                                               ; preds = %14
  %19 = sub i32 2030, %6
  br label %20

20:                                               ; preds = %12, %18, %16, %8
  %21 = phi i32 [ %9, %8 ], [ 610, %12 ], [ %17, %16 ], [ 30, %18 ]
  %22 = phi i32 [ 30, %8 ], [ %13, %12 ], [ 450, %16 ], [ %19, %18 ]
  br label %23

23:                                               ; preds = %28, %20
  %24 = phi i32 [ 0, %20 ], [ %29, %28 ]
  %25 = sub nsw i32 60, %24
  %26 = mul nsw i32 %25, %25
  %27 = sub nuw nsw i32 380, %24
  br label %31

28:                                               ; preds = %39
  %29 = add nuw nsw i32 %24, 1
  %30 = icmp eq i32 %29, 120
  br i1 %30, label %42, label %23, !llvm.loop !5

31:                                               ; preds = %39, %23
  %32 = phi i32 [ 0, %23 ], [ %40, %39 ]
  %33 = sub nsw i32 60, %32
  %34 = mul nsw i32 %33, %33
  %35 = add nuw nsw i32 %34, %26
  %36 = icmp ugt i32 %35, 3600
  br i1 %36, label %39, label %37

37:                                               ; preds = %31
  %38 = sub nuw nsw i32 300, %32
  call void @sim_put_pixel(i32 noundef %27, i32 noundef %38, i32 noundef -16776961) #5
  br label %39

39:                                               ; preds = %37, %31
  %40 = add nuw nsw i32 %32, 1
  %41 = icmp eq i32 %40, 120
  br i1 %41, label %28, label %31, !llvm.loop !8

42:                                               ; preds = %28, %47
  %43 = phi i32 [ %48, %47 ], [ 0, %28 ]
  %44 = sub nsw i32 30, %43
  %45 = mul nsw i32 %44, %44
  %46 = add nsw i32 %44, %21
  br label %50

47:                                               ; preds = %58
  %48 = add nuw nsw i32 %43, 1
  %49 = icmp eq i32 %48, 60
  br i1 %49, label %61, label %42, !llvm.loop !5

50:                                               ; preds = %58, %42
  %51 = phi i32 [ 0, %42 ], [ %59, %58 ]
  %52 = sub nsw i32 30, %51
  %53 = mul nsw i32 %52, %52
  %54 = add nuw nsw i32 %53, %45
  %55 = icmp ugt i32 %54, 900
  br i1 %55, label %58, label %56

56:                                               ; preds = %50
  %57 = add nsw i32 %52, %22
  call void @sim_put_pixel(i32 noundef %46, i32 noundef %57, i32 noundef -65536) #5
  br label %58

58:                                               ; preds = %56, %50
  %59 = add nuw nsw i32 %51, 1
  %60 = icmp eq i32 %59, 60
  br i1 %60, label %47, label %50, !llvm.loop !8

61:                                               ; preds = %47
  call void @draw_rays(i32 noundef %21, i32 noundef %22, i32 noundef 60, i32 noundef 720, i32 noundef %1, i32 noundef -65536)
  %62 = add nsw i32 %6, 4
  %63 = icmp sgt i32 %6, 1995
  %64 = select i1 %63, i32 0, i32 %62
  %65 = call i32 @sim_should_quit() #5
  %66 = icmp eq i32 %65, 0
  br i1 %66, label %5, label %4, !llvm.loop !15
}

declare i32 @sim_should_quit() local_unnamed_addr #1

declare void @sim_flush() local_unnamed_addr #1

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare i32 @llvm.smax.i32(i32, i32) #4

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare i32 @llvm.abs.i32(i32, i1 immarg) #4

attributes #0 = { nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nofree norecurse nosync nounwind readnone uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { mustprogress nofree nosync nounwind readnone uwtable willreturn "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #5 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{!"Debian clang version 14.0.6"}
!5 = distinct !{!5, !6, !7}
!6 = !{!"llvm.loop.mustprogress"}
!7 = !{!"llvm.loop.unroll.disable"}
!8 = distinct !{!8, !6, !7}
!9 = !{!10, !10, i64 0}
!10 = !{!"int", !11, i64 0}
!11 = !{!"omnipotent char", !12, i64 0}
!12 = !{!"Simple C/C++ TBAA"}
!13 = distinct !{!13, !6, !7}
!14 = distinct !{!14, !6, !7}
!15 = distinct !{!15, !7}
