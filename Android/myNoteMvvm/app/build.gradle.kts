plugins {
    alias(libs.plugins.android.application)
}

android {
    namespace = "com.example.mynotemvvm"
    compileSdk = 34

    defaultConfig {
        applicationId = "com.example.mynotemvvm"
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
    def lifecycle_version = "2.8.5"
    def arch_version = "2.2.0"
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
    // Annotation processor
    kapt (libs.lifecycle.compiler)
}