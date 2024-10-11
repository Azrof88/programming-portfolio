plugins {
    alias(libs.plugins.android.application)
}

android {
    namespace = "com.example.roomlib"
    compileSdk = 34
    buildFeatures()
    {
        viewBinding = true
    }


    defaultConfig {
        applicationId = "com.example.roomlib"
        minSdk = 24
        targetSdk = 34
        versionCode = 1
        versionName = "1.0"

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_1_8
        targetCompatibility = JavaVersion.VERSION_1_8
    }
}

dependencies {

    implementation(libs.appcompat)
    implementation(libs.material)
    implementation(libs.activity)
    implementation(libs.constraintlayout)
    testImplementation(libs.junit)
    androidTestImplementation(libs.ext.junit)
    androidTestImplementation(libs.espresso.core)
    // ViewModel
    implementation (libs.lifecycle.viewmodel.ktx)
    // ViewModel utilities for Compose
    implementation (libs.lifecycle.viewmodel.compose)
    // LiveData
    implementation (libs.lifecycle.livedata.ktx)
    // Saved state module for ViewModel
    implementation (libs.androidx.lifecycle.viewmodel.savedstate)

    // Annotation processor
    annotationProcessor (libs.androidx.lifecycle.compiler)
    // alternately - if using Java8, use the following instead of lifecycle-compiler
    implementation (libs.androidx.lifecycle.common.java8)

    // optional - helpers for implementing LifecycleOwner in a Service
    implementation (libs.androidx.lifecycle.service)

    // optional - ProcessLifecycleOwner provides a lifecycle for the whole application process
    implementation (libs.androidx.lifecycle.process)

    // optional - ReactiveStreams support for LiveData
    implementation (libs.androidx.lifecycle.reactivestreams)

    // optional - Test helpers for LiveData
    testImplementation (libs.androidx.core.testing)

    // optional - Test helpers for Lifecycle runtime
    testImplementation (libs.androidx.lifecycle.runtime.testing)
    implementation (libs.androidx.room.runtime)
    annotationProcessor( libs.androidx.room.compiler)

}