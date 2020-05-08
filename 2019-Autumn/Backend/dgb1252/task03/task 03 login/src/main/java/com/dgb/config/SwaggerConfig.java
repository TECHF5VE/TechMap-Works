package com.dgb.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.env.Environment;
import org.springframework.core.env.Profiles;
import springfox.documentation.builders.RequestHandlerSelectors;
import springfox.documentation.service.ApiInfo;
import springfox.documentation.service.Contact;
import springfox.documentation.spi.DocumentationType;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2;

import java.util.ArrayList;

/**
 * 接口管理
 */
@Configuration
@EnableSwagger2
public class SwaggerConfig {

    @Bean
    public Docket docket(Environment environment){
        Profiles profiles=Profiles.of("dev");
        boolean flag =environment.acceptsProfiles(profiles);
        return new Docket(DocumentationType.SWAGGER_2).apiInfo(apiInfo()).
                enable(flag).
                select().
                apis(RequestHandlerSelectors.basePackage("com.dgb.controller")).
                build();
    }

    private ApiInfo apiInfo(){
        Contact contact=new Contact("dgb", "", "1252294256@qq.com");
        return new ApiInfo("Api Documentation", "Api Documentation", "1.0", "urn:tos",
                contact, "Apache 2.0", "http://www.apache.org/licenses/LICENSE-2.0", new ArrayList<>());
    }
}
