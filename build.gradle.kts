plugins {
    id("com.android.application")                         id("org.jetbrains.kotlin.android")
    id("org.jetbrains.kotlin.plugin.compose")         }

android {
    namespace = "com.example.compose"
    compileSdk = 34
                                                          defaultConfig {
        applicationId = "com.example.compose"
        minSdk = 24                                           targetSdk = 34
        versionCode = 1
        versionName = "1.0"                               }

    buildFeatures {
        compose = true
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_21
        targetCompatibility = JavaVersion.VERSION_21
    }

    kotlinOptions {
        jvmTarget = "21"
    }
}

dependencies {
    val composeBom = platform("androidx.compose:compose-bom:2024.01.00")
    implementation(composeBom)
    implementation("androidx.compose.ui:ui")
    implementation("androidx.compose.material3:material3")
    implementation("androidx.activity:activity-compose:1.8.2")
    implementation("androidx.core:core-ktx:1.12.0")
    implementation("androidx.navigation:navigation-compose:2.8.5")


}
