#include "Framework.h"
#include "AnimationRect.h"

#include "Utilities/Animator.h"

AnimationRect::AnimationRect(Vector3 position, Vector3 size)
    : TextureRect(position, size, 0.0f)
{
    animator = new Animator();

    {
        Texture2D* srcTex = new Texture2D(TexturePath + L"player.png");
        AnimationClip* RunD = new AnimationClip
        (
            L"RunD", srcTex, 1,
            Values::ZeroVec2, Vector2(srcTex->GetWidth(), srcTex->GetHeight())
        );
        AnimationClip* RunL = new AnimationClip
        (
            L"RunL", srcTex, 10,
            Vector2(0, srcTex->GetHeight() * 0.27f),
            Vector2(srcTex->GetWidth(), srcTex->GetHeight() - srcTex->GetHeight() * 0.5f), true
        ); 
        AnimationClip* RunU = new AnimationClip
        (
            L"RunU", srcTex, 10,
            Vector2(0, srcTex->GetHeight() * 0.5f),
            Vector2(srcTex->GetWidth(), srcTex->GetHeight() - srcTex->GetHeight() * 0.25f), true
        );
        
        AnimationClip* RunR = new AnimationClip
        (
            L"RunR", srcTex, 10,
            Vector2(0, srcTex->GetHeight() * 0.75f),
            Vector2(srcTex->GetWidth(), srcTex->GetHeight()), true
        );
        
        animator->AddAnimClip(RunR);
        animator->AddAnimClip(RunL);
        animator->AddAnimClip(RunU);
        animator->AddAnimClip(RunD);
        animator->SetCurrentAnimClip(L"RunD");
        SAFE_DELETE(srcTex);
    }

    //Sampler
    {
        D3D11_SAMPLER_DESC desc;
        States::GetSamplerDesc(&desc);
        States::CreateSampler(&desc, &point[0]);

        desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
        States::CreateSampler(&desc, &point[1]);
    }

    //Blend
    {
        D3D11_BLEND_DESC desc;
        States::GetBlendDesc(&desc);
        States::CreateBlend(&desc, &bpoint[0]);

        desc.RenderTarget[0].BlendEnable = true;
        States::CreateBlend(&desc, &bpoint[1]);
    }

    // 0 - 비활성화
    // 1 - 활성화
}

AnimationRect::~AnimationRect()
{
}

void AnimationRect::Update()
{
    animator->Update();

    MapVertexBuffer();
    {
        vertices[0].uv.x = animator->GetCurrentFrame().x;
        vertices[0].uv.y = animator->GetCurrentFrame().y + animator->GetTexelFrameSize().y;

        vertices[1].uv.x = animator->GetCurrentFrame().x + animator->GetTexelFrameSize().x;
        vertices[1].uv.y = animator->GetCurrentFrame().y;

        vertices[2].uv.x = animator->GetCurrentFrame().x + animator->GetTexelFrameSize().x;
        vertices[2].uv.y = animator->GetCurrentFrame().y + animator->GetTexelFrameSize().y;

        vertices[3].uv.x = animator->GetCurrentFrame().x;
        vertices[3].uv.y = animator->GetCurrentFrame().y;

    }
    UnmapVertexBuffer();

    __super::Update();
}

void AnimationRect::Render()
{
    srv = animator->GetCurrentSRV();

    //DC->PSGetSamplers(0, 1, &point[0]);                            //선형보간
    //DC->OMSetBlendState(bpoint[0], nullptr, (UINT)0xFFFFFFFF);     //블렌드 비활성화

    //DC->PSGetSamplers(0, 1, &point[1]);                            //포인트보간
    //DC->OMSetBlendState(bpoint[0], nullptr, (UINT)0xFFFFFFFF);     //플렌드 비활성화

    DC->PSGetSamplers(0, 1, &point[1]);                            //포인트보간
    DC->OMSetBlendState(bpoint[1], nullptr, (UINT)0xFFFFFFFF);     //플렌드 활성화
    __super::Render();
}

void AnimationRect::Move()
{
    auto key = Keyboard::Get();
    auto delta = Time::Delta();

    if (key->Press('D'))
    {
        position.x += 100 * delta;
        animator->SetCurrentAnimClip(L"RunD");
    }
    if(key->Press('A'))
    {
        position.x -= 100 * delta;
        animator->SetCurrentAnimClip(L"RunD");
    }
    if (key->Press('W'))
    {
        position.y += 100 * delta;
        animator->SetCurrentAnimClip(L"RunD");
    }
    if (key->Press('S'))
    {
        position.y -= 100 * delta;
        animator->SetCurrentAnimClip(L"RunD");
    }
 
}
