; ModuleID = 'app.c'
source_filename = "app.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind optsize uwtable
define dso_local i32 @calculate_ray_length() local_unnamed_addr #0 {
  %1 = tail call i32 @sim_sqrt(i32 noundef 640000) #4
  ret i32 %1
}

; Function Attrs: optsize
declare i32 @sim_sqrt(i32 noundef) local_unnamed_addr #1

; Function Attrs: nounwind optsize uwtable
define dso_local void @draw_circle(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3) local_unnamed_addr #0 {
  %5 = icmp sgt i32 %2, 0
  br i1 %5, label %6, label %15

6:                                                ; preds = %4
  %7 = shl nuw i32 %2, 1
  %8 = mul nuw nsw i32 %2, %2
  %9 = tail call i32 @llvm.smax.i32(i32 %7, i32 1)
  br label %10

10:                                               ; preds = %16, %6
  %11 = phi i32 [ 0, %6 ], [ %17, %16 ]
  %12 = sub nsw i32 %2, %11
  %13 = mul nsw i32 %12, %12
  %14 = add nsw i32 %12, %0
  br label %19

15:                                               ; preds = %16, %4
  ret void

16:                                               ; preds = %27
  %17 = add nuw nsw i32 %11, 1
  %18 = icmp eq i32 %17, %9
  br i1 %18, label %15, label %10, !llvm.loop !5

19:                                               ; preds = %10, %27
  %20 = phi i32 [ 0, %10 ], [ %28, %27 ]
  %21 = sub nsw i32 %2, %20
  %22 = mul nsw i32 %21, %21
  %23 = add nuw nsw i32 %22, %13
  %24 = icmp ugt i32 %23, %8
  br i1 %24, label %27, label %25

25:                                               ; preds = %19
  %26 = add nsw i32 %21, %1
  tail call void @sim_put_pixel(i32 noundef %14, i32 noundef %26, i32 noundef %3) #4
  br label %27

27:                                               ; preds = %25, %19
  %28 = add nuw nsw i32 %20, 1
  %29 = icmp eq i32 %28, %9
  br i1 %29, label %16, label %19, !llvm.loop !7
}

; Function Attrs: mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #2

; Function Attrs: optsize
declare void @sim_put_pixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #1

; Function Attrs: mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.end.p0(i64 immarg, ptr nocapture) #2

; Function Attrs: nounwind optsize uwtable
define dso_local range(i32 0, 2) i32 @has_interception(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6) local_unnamed_addr #0 {
  %8 = sub nsw i32 %3, %1
  %9 = mul nsw i32 %8, %4
  %10 = sub nsw i32 %2, %0
  %11 = mul nsw i32 %2, %1
  %12 = mul i32 %3, %0
  %13 = mul i32 %10, %5
  %14 = add i32 %13, %12
  %15 = add i32 %9, %11
  %16 = sub i32 %15, %14
  %17 = tail call i32 @llvm.abs.i32(i32 %16, i1 true)
  %18 = mul nsw i32 %8, %8
  %19 = mul nsw i32 %10, %10
  %20 = add nuw nsw i32 %18, %19
  %21 = tail call i32 @sim_sqrt(i32 noundef %20) #4
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

; Function Attrs: nounwind optsize uwtable
define dso_local void @calc_interception(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, ptr nocapture noundef writeonly %7, ptr nocapture noundef writeonly %8) local_unnamed_addr #0 {
  %10 = sub nsw i32 %4, %0
  %11 = mul nsw i32 %10, %10
  %12 = sub nsw i32 %5, %1
  %13 = mul nsw i32 %12, %12
  %14 = add nuw nsw i32 %13, %11
  %15 = tail call i32 @sim_sqrt(i32 noundef %14) #4
  %16 = sub nsw i32 %15, %6
  %17 = sub nsw i32 %2, %0
  %18 = sub nsw i32 %3, %1
  %19 = mul nsw i32 %17, %17
  %20 = mul nsw i32 %18, %18
  %21 = add nuw nsw i32 %20, %19
  %22 = tail call i32 @sim_sqrt(i32 noundef %21) #4
  %23 = icmp slt i32 %6, 0
  br i1 %23, label %48, label %24

24:                                               ; preds = %9
  %25 = sub i32 %0, %4
  %26 = sub i32 %1, %5
  %27 = mul nuw nsw i32 %6, %6
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
  br i1 %47, label %48, label %28, !llvm.loop !8

48:                                               ; preds = %28, %9
  %49 = phi i32 [ %16, %9 ], [ %46, %28 ]
  %50 = mul nsw i32 %49, %17
  %51 = sdiv i32 %50, %22
  %52 = add nsw i32 %51, %0
  store i32 %52, ptr %7, align 4, !tbaa !9
  %53 = mul nsw i32 %49, %18
  %54 = sdiv i32 %53, %22
  %55 = add nsw i32 %54, %1
  store i32 %55, ptr %8, align 4, !tbaa !9
  ret void
}

; Function Attrs: nounwind optsize uwtable
define dso_local void @draw_rays(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5) local_unnamed_addr #0 {
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = sdiv i32 1440, %3
  %10 = icmp sgt i32 %3, 0
  br i1 %10, label %12, label %11

11:                                               ; preds = %29, %6
  ret void

12:                                               ; preds = %6, %29
  %13 = phi i32 [ %30, %29 ], [ 0, %6 ]
  %14 = mul nuw nsw i32 %13, %9
  %15 = tail call i32 @get_sin_precise(i32 noundef %14) #4
  %16 = tail call i32 @get_cos_precise(i32 noundef %14) #4
  %17 = mul nsw i32 %16, %4
  %18 = sdiv i32 %17, 65535
  %19 = add nsw i32 %18, %0
  %20 = mul nsw i32 %15, %4
  %21 = sdiv i32 %20, 65535
  %22 = add nsw i32 %21, %1
  %23 = tail call i32 @has_interception(i32 noundef %0, i32 noundef %1, i32 noundef %19, i32 noundef %22, i32 noundef 320, i32 noundef 240, i32 noundef %2) #5
  %24 = icmp eq i32 %23, 0
  br i1 %24, label %25, label %26

25:                                               ; preds = %12
  tail call void @sim_draw_line(i32 noundef %0, i32 noundef %1, i32 noundef %19, i32 noundef %22, i32 noundef %5) #4
  br label %29

26:                                               ; preds = %12
  call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %7) #6
  store i32 0, ptr %7, align 4, !tbaa !9
  call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %8) #6
  store i32 0, ptr %8, align 4, !tbaa !9
  call void @calc_interception(i32 noundef %0, i32 noundef %1, i32 noundef %19, i32 noundef %22, i32 noundef 320, i32 noundef 240, i32 noundef %2, ptr noundef nonnull %7, ptr noundef nonnull %8) #5
  %27 = load i32, ptr %7, align 4, !tbaa !9
  %28 = load i32, ptr %8, align 4, !tbaa !9
  tail call void @sim_draw_line(i32 noundef %0, i32 noundef %1, i32 noundef %27, i32 noundef %28, i32 noundef %5) #4
  call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %8) #6
  call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %7) #6
  br label %29

29:                                               ; preds = %26, %25
  %30 = add nuw nsw i32 %13, 1
  %31 = icmp eq i32 %30, %3
  br i1 %31, label %11, label %12, !llvm.loop !13
}

; Function Attrs: optsize
declare i32 @get_sin_precise(i32 noundef) local_unnamed_addr #1

; Function Attrs: optsize
declare i32 @get_cos_precise(i32 noundef) local_unnamed_addr #1

; Function Attrs: optsize
declare void @sim_draw_line(i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #1

; Function Attrs: nounwind optsize uwtable
define dso_local void @app() local_unnamed_addr #0 {
  %1 = tail call i32 @sim_sqrt(i32 noundef 640000) #4
  %2 = tail call i32 @sim_should_quit() #4
  %3 = icmp eq i32 %2, 0
  br i1 %3, label %5, label %4

4:                                                ; preds = %20, %0
  ret void

5:                                                ; preds = %0, %20
  %6 = phi i32 [ %25, %20 ], [ 0, %0 ]
  tail call void @sim_flush() #4
  %7 = icmp slt i32 %6, 580
  br i1 %7, label %8, label %10

8:                                                ; preds = %5
  %9 = add nsw i32 %6, 30
  br label %20

10:                                               ; preds = %5
  %11 = icmp ult i32 %6, 1000
  br i1 %11, label %12, label %14

12:                                               ; preds = %10
  %13 = add nsw i32 %6, -550
  br label %20

14:                                               ; preds = %10
  %15 = icmp ult i32 %6, 1580
  br i1 %15, label %16, label %18

16:                                               ; preds = %14
  %17 = sub nuw nsw i32 1610, %6
  br label %20

18:                                               ; preds = %14
  %19 = sub nsw i32 2030, %6
  br label %20

20:                                               ; preds = %12, %18, %16, %8
  %21 = phi i32 [ %9, %8 ], [ 610, %12 ], [ %17, %16 ], [ 30, %18 ]
  %22 = phi i32 [ 30, %8 ], [ %13, %12 ], [ 450, %16 ], [ %19, %18 ]
  tail call void @draw_circle(i32 noundef 320, i32 noundef 240, i32 noundef 60, i32 noundef -16776961) #5
  tail call void @draw_circle(i32 noundef %21, i32 noundef %22, i32 noundef 30, i32 noundef -65536) #5
  tail call void @draw_rays(i32 noundef %21, i32 noundef %22, i32 noundef 60, i32 noundef 720, i32 noundef %1, i32 noundef -65536) #5
  %23 = add nsw i32 %6, 4
  %24 = icmp sgt i32 %6, 1995
  %25 = select i1 %24, i32 0, i32 %23
  %26 = tail call i32 @sim_should_quit() #4
  %27 = icmp eq i32 %26, 0
  br i1 %27, label %5, label %4
}

; Function Attrs: optsize
declare i32 @sim_should_quit() local_unnamed_addr #1

; Function Attrs: optsize
declare void @sim_flush() local_unnamed_addr #1

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare i32 @llvm.smax.i32(i32, i32) #3

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare i32 @llvm.abs.i32(i32, i1 immarg) #3

attributes #0 = { nounwind optsize uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { optsize "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }
attributes #3 = { nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #4 = { nounwind optsize }
attributes #5 = { optsize }
attributes #6 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"Debian clang version 19.1.7 (3~deb12u1)"}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.mustprogress"}
!7 = distinct !{!7, !6}
!8 = distinct !{!8, !6}
!9 = !{!10, !10, i64 0}
!10 = !{!"int", !11, i64 0}
!11 = !{!"omnipotent char", !12, i64 0}
!12 = !{!"Simple C/C++ TBAA"}
!13 = distinct !{!13, !6}
